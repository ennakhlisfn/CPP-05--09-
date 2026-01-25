#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- TEST 1: Form Creation ---" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 100);
        std::cout << "Created: " << taxForm << std::endl;
        std::cout << "Attempting to create invalid form..." << std::endl;
        Form trashForm("Trash", 151, 150);
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Signing Mechanics ---" << std::endl;
    
    Bureaucrat boss("The Boss", 5);
    Bureaucrat intern("The Intern", 145);

    Form importantContract("Important Contract", 10, 10); 
    Form coffeeOrder("Coffee Order", 140, 140);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--- Scenario A: Intern tries to work ---" << std::endl;
    intern.signForm(importantContract);
    
    intern.signForm(coffeeOrder);

    std::cout << "\n--- Scenario B: Boss steps in ---" << std::endl;
    boss.signForm(importantContract);

    boss.signForm(coffeeOrder);

    std::cout << "\n--- Final Form Status ---" << std::endl;
    std::cout << importantContract << std::endl;
    std::cout << coffeeOrder << std::endl;

    return 0;
}