#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
    
        virtual ~AForm();
    
        AForm(const std::string& name, int signGrade, int execGrade);
    
        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
    
        void beSigned(const Bureaucrat& bureaucrat);
    
        virtual void execute(Bureaucrat const & executor) const = 0;
    
        class GradeTooHighException : public std::exception {
            public: virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
            public: virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif