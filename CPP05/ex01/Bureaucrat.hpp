#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;
class Bureaucrat{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

        void    signForm(Form& form) const;

        class GradeTooHighException : public std::exception{
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw();
        };

        void incrementing();
        void decrementing();

        const std::string getName() const;
        int getGrade() const;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj);

#endif