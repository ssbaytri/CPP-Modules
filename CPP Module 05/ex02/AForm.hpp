#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExec;
    const std::string _target;

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target);
    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    ~AForm();

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    const std::string& getTarget() const;

    virtual void execute(Bureaucrat const & executor) const = 0;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};


std::ostream& operator<<(std::ostream& out, const AForm& form);
