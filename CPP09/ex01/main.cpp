#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    RPN calculator;
    calculator.processExpression(argv[1]);

    return 0;
}