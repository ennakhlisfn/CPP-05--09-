#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& s) const {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

void RPN::calculate(const std::string& op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: insufficient operands.");
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == "+") _stack.push(a + b);
    else if (op == "-") _stack.push(a - b);
    else if (op == "*") _stack.push(a * b);
    else if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: division by zero.");
        _stack.push(a / b);
    }
}

void RPN::processExpression(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    try {
        while (ss >> token) {
            if (isdigit(token[0]) && token.length() == 1) {
                _stack.push(std::atoi(token.c_str()));
            } else if (isOperator(token)) {
                calculate(token);
            } else {
                throw std::runtime_error("Error: invalid character.");
            }
        }

        if (_stack.size() != 1) {
            throw std::runtime_error("Error: expression is incomplete.");
        }

        std::cout << _stack.top() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        while (!_stack.empty()) _stack.pop();
    }
}