#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade Too Low";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100)
{
	std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Custom Constructor" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy Constructor" << std::endl;;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout << "Copy Assignment Operator" << std::endl;;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
