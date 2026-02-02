#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <stdlib.h>

class RPN {
    private:
        std::stack<int> _stack;

        bool isOperator(const std::string& s) const;
        void calculate(const std::string& op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void processExpression(const std::string& expression);
};

#endif