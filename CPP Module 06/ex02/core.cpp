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

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Undefined Class" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast& e) {}

	try
	{
		(void)(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast& e) {}

	try
	{
		(void)(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast& e) {}
}
