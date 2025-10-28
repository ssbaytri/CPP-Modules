#include "Intern.hpp"

int main ()
{
    Intern someRandomIntern;
    Bureaucrat boss("$ubZero", 1);
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

    boss.signForm(*rrf);
    boss.executeForm(*rrf);

    std::cout << *rrf << std::endl;

    delete rrf;
    return 0;
}