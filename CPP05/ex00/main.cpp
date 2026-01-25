#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << " created successfully." << std::endl;
        bob.incrementing();
        std::cout << bob << std::endl;
        bob.incrementing();
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jim("Jim", 155);
        std::cout << "This message will not appear." << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}