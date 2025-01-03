#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie()
{
	this->name = "Unknown";
	std::cout << "Zombie ctor with params is called" << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie ctor with params is called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie dtor is called ->";
	std::cout << this->name << " is destroyed" << std::endl;
}
