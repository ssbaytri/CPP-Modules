#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	srand(time(0));

    Bureaucrat bureaucrat =  Bureaucrat("$ubZ3r0", 1);
    ShrubberyCreationForm shrubberyForm =  ShrubberyCreationForm("1");
    RobotomyRequestForm robotomyForm =  RobotomyRequestForm("2");
    PresidentialPardonForm presidentialForm =  PresidentialPardonForm("3");

    std::cout << bureaucrat << std::endl;
    std::cout << shrubberyForm << std::endl;;
    std::cout << robotomyForm << std::endl;;
    std::cout << presidentialForm << std::endl;;

    bureaucrat.signForm(shrubberyForm);
    bureaucrat.executeForm(shrubberyForm);

    bureaucrat.signForm(robotomyForm);
    bureaucrat.executeForm(robotomyForm);

    bureaucrat.signForm(presidentialForm);
    bureaucrat.executeForm(presidentialForm);

    std::cout << shrubberyForm << std::endl;;
    std::cout << robotomyForm << std::endl;;
    std::cout << presidentialForm << std::endl;;

    return 0;
}