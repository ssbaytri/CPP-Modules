#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat obj("$ubZ3r0", 2);
		std::cout << obj << std::endl;
		obj.incrementGrade();
		std::cout << obj << std::endl;
		obj.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}