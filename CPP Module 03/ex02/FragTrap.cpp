#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;
	std::cout << "FragTrap " << this->_name << " constructed with high energy and excitement!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->_name << " copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << this->_name << " assigned!" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " self-destructs with a smile!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_HP <= 0 || _EP <= 0)
	{
		std::cout << "FragTrap " << _name << " can't attack: not enough hit points or energy!" << std::endl;
        return;
	}
	--_EP;
	std::cout << "FragTrap " << _name << " launches an explosive attack on " << target
              << ", dealing " << _AD << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " throws up a high five! ✋ Let's gooo!" << std::endl;
}

