#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	std::string name_z;
    Zombie  *zombie;

	getline(std::cin, name_z);
	zombie = newZombie(name_z);
	zombie->announce();
	std::cout << "ayjm s tacki mej stexcvac zombin" <<std::endl;
	randomChump("esel senc");
	delete zombie;

}