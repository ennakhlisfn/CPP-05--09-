#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
class AForm;
class Bureaucrat{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

        void    signForm(AForm& form) const;
        void    executeForm(AForm const & form);

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