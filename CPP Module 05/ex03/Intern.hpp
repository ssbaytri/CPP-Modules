#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		AForm *makePresidentialPardonForm(const std::string& target);
        AForm *makeRobotomyRequestForm(const std::string& target);
        AForm *makeShrubberyCreationForm(const std::string& target);
};