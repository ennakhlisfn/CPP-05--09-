#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;

    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        Form(const std::string& _name, int _signGrade, int _execGrade);

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif