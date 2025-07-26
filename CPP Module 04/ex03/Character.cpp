#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
