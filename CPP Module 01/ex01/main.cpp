#include "Zombie.hpp"

int main()
{
    int hordeSize = 0;
    Zombie* horde = zombieHorde(hordeSize, "HordeZombie");
    if (!horde)
        return 1;
    for(int i = 0; i < hordeSize; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}