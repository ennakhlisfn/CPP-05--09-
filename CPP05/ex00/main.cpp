#include "Bureaucrat.hpp"

int main() {
    // TEST 1: Valid instantiation
    try {
        Bureaucrat bob("Bob", 2); // This works fine
        std::cout << bob.getName() << " created successfully." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // TEST 2: Invalid instantiation (Too Low)
    try {
        Bureaucrat jim("Jim", 155); // This will THROW GradeTooLowException
        
        // This line below will NEVER execute because the throw stops it
        std::cout << "This message will not appear." << std::endl;
    }
    catch (std::exception &e) {
        // The program jumps here immediately
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}