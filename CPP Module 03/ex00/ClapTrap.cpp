#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _HP(10), _EP(10), _AD(0)
{
	std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _HP(other._HP), _EP(other._EP), _AD(other._AD)
{
	std::cout << "ClapTrap " << this->_name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	std::cout << "ClapTrap " << this->_name << " assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if (_HP <= 0 || _EP <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack: not enough hit points or energy!" << std::endl;
		return ;
	}
	--_EP;
	std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _AD << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_HP -= amount;
	if (_HP < 0) _HP = 0;
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage! "
              << "Remaining HP: " << _HP << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HP <= 0 || _EP <= 0) {
        std::cout << "ClapTrap " << _name << " can't repair: not enough hit points or energy!" << std::endl;
        return ;
    }
	--_EP;
	_HP += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " hit points! New HP: " << _HP << std::endl;
}
