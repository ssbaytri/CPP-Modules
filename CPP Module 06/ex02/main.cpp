#include "core.hpp"

int main()
{
    std::cout << "Test 1: Generate random object" << std::endl;
    Base* obj1 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj1);
    std::cout << "Identify with reference: ";
    identify(*obj1);
    std::cout << std::endl;


    std::cout << "Test 2: Manually created" << std::endl;
    Base* man = new B;
    std::cout << "Identify with pointer: ";
    identify(man);
    std::cout << "Identify with reference: ";
    identify(*man);
    std::cout << std::endl;

	delete obj1;
	delete man;

	return 0;
}