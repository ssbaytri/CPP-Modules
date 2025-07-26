#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice: Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

