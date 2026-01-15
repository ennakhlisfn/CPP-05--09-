#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName(){
    return name;
}

int Bureaucrat::getGrade(){
    return grade;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade){
    if (_grade < 1)
        
    name = _name;
    grade = _grade;
}