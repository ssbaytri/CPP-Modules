#include "core.hpp"
#include <ctime>

Base* generate(void)
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	switch(random)
	{
		case 0 : return new A;
		case 1 : return new B;
		default :  return new C;
	}
}