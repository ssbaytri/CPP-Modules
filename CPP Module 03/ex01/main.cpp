#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap test("hello");
	test.attack("another");
    ScavTrap ahya("james");
    ahya.attack("hello");
    ahya.guardGate();

    // ClapTrap* bot = new ScavTrap("shadow");
    // delete bot;

    return 0;
}
