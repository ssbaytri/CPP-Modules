#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->value = other.value;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->value = raw;
}
