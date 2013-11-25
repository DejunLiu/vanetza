#ifndef LIFETIME_HPP_XYTSNW3J
#define LIFETIME_HPP_XYTSNW3J

#include <vanetza/common/bit_number.hpp>
#include <cstdint>

namespace vanetza
{
namespace geonet
{

class Lifetime
{
public:
    static const uint8_t multiplier_mask = 0xFC;
    static const uint8_t base_mask = 0x03;

    enum class Base {
        _50_MS = 0,
        _1_S = 1,
        _10_S = 2,
        _100_S = 3
    };

    Lifetime();
    Lifetime(Base base, BitNumber<uint8_t, 6> multiplier);
    void set(Base base, BitNumber<uint8_t, 6> multiplier);
    uint8_t raw() const { return m_lifetime; }
    void raw(uint8_t raw) { m_lifetime = raw; }

    /**
     * Decodes stored lifetime to a double value
     * \return lifetime in seconds
     */
    double decode() const;

    /**
     * Encode seconds in lifetime object
     * \note Precision loss might occur
     * \param seconds Number of seconds
     */
    void encode(double seconds);

private:
    uint8_t m_lifetime;
};

} // namespace geonet
} // namespace vanetza

#endif /* LIFETIME_HPP_XYTSNW3J */
