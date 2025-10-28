#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form Not Signed";
}

AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExec(150), _target("default")
{
    std::cout << "Form Default Constructor" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target)
     : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target(target)
{
    std::cout << "Form New Parameterized Constructor" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Form Parameterized Constructor" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _target(other._target)
{
    std::cout << "Form Copy Constructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Form Copy Assignment Operator" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Form Destructor" << std::endl;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

const std::string &AForm::getTarget() const
{
    return _target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form: " << form.getName() 
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExec();
    return out;
}
