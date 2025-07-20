#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->_HP = 100;
    this->_EP = 50;
    this->_AD = 20;
    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->_name << " copy constructed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << this->_name << " assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_HP <= 0 || _EP <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack: not enough hit points or energy!" << std::endl;
        return;
    }
    --_EP;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target
              << ", dealing " << _AD << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
}

