#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

void ll()
{
	system("leaks rpg");
}

int main(void)
{
	atexit(ll);
	AMateria* a = new Ice();
	AMateria* b = new Cure();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(a);
	src->learnMateria(b);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete a;
	delete b;

	delete bob;
	delete me;
	delete src;

	return 0;
}