#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << "Intern Copy Constructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Assignment Operator" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*fun[3])(const std::string& target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*fun[i])(target);
		}
	}
	std::cout << "Intern could not find the form: " << formName << std::endl;
	return NULL;
}