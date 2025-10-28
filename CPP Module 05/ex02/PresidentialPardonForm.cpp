#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5, "default_target")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5, target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}