#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap test("hello");
	test.attack("another");
    ScavTrap ahya("james");
    ahya.attack("hello");
    ahya.guardGate();
    return 0;
}
