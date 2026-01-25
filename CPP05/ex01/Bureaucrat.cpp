#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name){
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = _grade;
}


void Bureaucrat::signForm(Form& form) const{
    try{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e){
        std::cout << name << " couldn't sign " << form.getName()
                << " because "<< e.what() << std::endl; 
    }
}


const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high. (Highest possible is 1)";
}
const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low. (lowest possible is 150)";
}

void Bureaucrat::incrementing(){
    int gr = grade;
    if (--gr < 1)
        throw Bureaucrat::GradeTooHighException();
    grade = gr;
}

void Bureaucrat::decrementing(){
    int gr = grade;
    if (++gr > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = gr;
}

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& obj){
    output << "name: " << obj.getName() << "   grade: " << obj.getGrade();
    return output;
}