#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception{
            
        };
        class GradeTooLowException();

        const std::string getName();
        int getGrade();
};



#endif