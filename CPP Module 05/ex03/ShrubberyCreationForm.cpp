#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137, "default_target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::ofstream file;
	file.open((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return ;
	}
	file << 
				"        	# #### ####				\n"
				"        ### \\/#|### |/####		\n"
				"       ##\\/#/ \\||/##/_/##/_#		\n"
				"     ###  \\/###|/ \\/ # ###		\n"
				"   ##_\\_#\\_\\## | #/###_/_####	\n"
				"  ## #### # \\ #| /  #### ##/##	\n"
				"   __#_--###`  |{,###---###-~		\n"
				"             \\ }{					\n"
				"              }}{					\n"
				"              }}{					\n"
				"         ejm  {{}					\n"
				"        , -=-~{ .-^- _				\n"
				"              `}					\n"
				"               {					\n";
	file.close();
}
