#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default ctor is called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& other) : fixed_point_value(other.fixed_point_value)
{
    std::cout << "copy ctor is called" << std::endl;
    // *this = other;
}


Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "copy assignment is called" << std::endl;
    if (this == &other)
        return (*this);
    this->fixed_point_value = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits is called" << std::endl;
    this->fixed_point_value = raw;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits is called" << std::endl;
    return (this->fixed_point_value);
}

Fixed::~Fixed()
{
    std::cout << "dtor is called" << std::endl;
}