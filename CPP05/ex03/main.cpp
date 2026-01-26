#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "---------------------------------" << std::endl;

    AForm* wrong;
    wrong = someRandomIntern.makeForm("coffee request", "Boss");

    if (wrong) {
        boss.signForm(*wrong);
        delete wrong;
    }

    return 0;
}