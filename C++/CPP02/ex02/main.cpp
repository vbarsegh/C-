#include "Fixed.hpp"
int main( void ) {
    Fixed a(100);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a-- << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}
