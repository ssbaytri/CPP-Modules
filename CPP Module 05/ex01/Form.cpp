#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Form Parameterized Constructor" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "Form Copy Constructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form Copy Assignment Operator" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form Destructor" << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form: " << form.getName() 
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExec();
    return out;
}
