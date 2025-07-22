#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("Heisenberg");

    d.attack("Jesse");
    d.takeDamage(40);
    d.beRepaired(20);
    d.whoAmI();

    DiamondTrap copy(d);
    copy.whoAmI();

    DiamondTrap assigned("Temporary");
    assigned = d;
    assigned.whoAmI();

    // ScavTrap* another = new DiamondTrap("james");
    // delete another;

    return 0;
}
