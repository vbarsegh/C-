#include "HumanA.hpp"
#include "HumanB.hpp"
// #include "Weapon.hpp"
int main()
{
    {
    Weapon club = Weapon("crude spiked club");
    // std::cout << "1" << std::endl;
    HumanA bob("Bob", club);
    // std::cout << "2" << std::endl;
    bob.attack();
    club.setType("some other type of club");
    // std::cout << "hres" << club.getType() <<  std::endl;
    bob.attack();
    }
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(&club);//bayc ira tvacov aranc &-ia club@???????
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    return 0;
}