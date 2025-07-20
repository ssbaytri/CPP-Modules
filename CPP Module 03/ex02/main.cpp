#include "FragTrap.hpp"

int main() {
    FragTrap frodo("Frodo");

    frodo.attack("Orc");
    frodo.takeDamage(25);
    frodo.beRepaired(15);
    frodo.highFivesGuys();

    for (int i = 0; i < 5; ++i)
        frodo.attack("Orc");

    frodo.takeDamage(100);
    frodo.attack("james");
    frodo.beRepaired(20);
    frodo.highFivesGuys();

    return 0;
}
