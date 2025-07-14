#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int value;
        static const int fractionalBits;

    public:
    Fixed();                                // Default constructor
    Fixed(const Fixed& other);              // Copy constructor
    Fixed& operator=(const Fixed& other);   // Copy assignment operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
