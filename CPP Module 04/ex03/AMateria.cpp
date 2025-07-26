#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria: Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << "AMateria: Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
