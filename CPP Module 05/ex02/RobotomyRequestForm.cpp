#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45, "default_target")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45, target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::cout << "Bzzzzzz... Vrrrrrrr... (drilling noises)" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
}