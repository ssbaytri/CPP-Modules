#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_HP = 100;				// from FragTrap
	_EP = 50;				// from ScavTrap
	_AD = 30;				// from FragTrap

	std::cout << "DiamondTrap " << this->_name << " has been forged from pure legacy metal!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << this->_name << " has been copy-forged!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap " << this->_name << " has been reassigned!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " has been shattered!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target); // Use of ScavTrap attack method;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name
              << ": Who am I? I am " << _name
              << " and my ClapTrap name is " << ClapTrap::_name << "!" << std::endl;
}

