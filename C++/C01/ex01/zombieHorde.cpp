#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* z = new Zombie[N];

	int i;
	for (i = 0; i < N; i++)
		z[i] = Zombie(name + std::to_string(i + 1));
	return (z);
}