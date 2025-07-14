#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits;

    public:
    Fixed();                                // Default constructor
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);              // Copy constructor
    Fixed& operator=(const Fixed& other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
