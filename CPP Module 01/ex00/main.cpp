#include "Zombie.hpp"

int main()
{
    Zombie *z1 = newZombie("heap allocated Zombie");
    z1->announce();
    delete z1;

    randomChump("stack allocated Zombie");

    return 0;
}
