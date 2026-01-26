#include <iostream>
#include <ctime>   // For randomness
#include <cstdlib> // For srand

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- CREATING BUREAUCRATS ---" << std::endl;
    Bureaucrat boss("The Boss", 1);
    Bureaucrat senior("Senior Staff", 40);
    Bureaucrat intern("Intern", 149);

    std::cout << boss << std::endl;
    std::cout << senior << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- CREATING FORMS ---" << std::endl;
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n--- TEST 1: SHRUBBERY (Low Level) ---" << std::endl;
    intern.signForm(shrub);
    intern.executeForm(shrub);
    senior.executeForm(shrub);

    std::cout << "\n--- TEST 2: ROBOTOMY (Mid Level & Randomness) ---" << std::endl;
    senior.signForm(shrub);
    senior.executeForm(shrub);
    senior.signForm(robot);
    senior.executeForm(robot);
    senior.executeForm(robot);
    senior.executeForm(robot);
    senior.executeForm(robot);

    std::cout << "\n--- TEST 3: PARDON (High Level) ---" << std::endl;
    senior.signForm(pardon);
    boss.signForm(pardon);
    senior.executeForm(pardon);
    boss.executeForm(pardon);

    return 0;
}