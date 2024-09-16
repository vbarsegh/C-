#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->wp1 = NULL;
    std::cout << "HumanB ctor with params is called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB dtor is called" << std::endl;
}

void    HumanB::attack()
{
    if (this->wp1 == NULL)
        std::cout << name << " has no weapon" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->wp1->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon *club)
{
    this->wp1 = club;
}