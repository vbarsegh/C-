#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	std::string name_z;
    int N;
    std::cout << "N = ";
    std::cin >> N;
    std::cout << "Xi ches ashxatum ara" <<std::endl;
    Zombie  *zombie;

    
	getline(std::cin, name_z);
	zombie = zombieHorde(N, name_z);
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
	delete[] zombie;

}