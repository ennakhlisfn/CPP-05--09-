#include "Form.hpp"

Form::Form(): name(), isSigned(false), signGrade(), execGrade() {}

Form::Form(const Form& other): name(other.getName()), isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()) {}

Form& Form::operator=(const Form& other){
    if(this == &other) return *this;

    isSigned = other.getIsSigned();
    return *this;
}

Form::~Form(){}

Form::Form(const std::string& _name, int _signGrade, int _execGrade): name(_name), isSigned(false), signGrade(_signGrade), execGrade(_execGrade){
    if (_signGrade < 1 || _execGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade > 150 || _execGrade > 150)
        throw Form::GradeTooLowException();
}

std::string Form::getName() const{
    return name;
}
bool Form::getIsSigned() const{
    return isSigned;
}
int Form::getSignGrade() const{
    return signGrade;
}
int Form::getExecGrade() const{
    return execGrade;
}

void Form::beSigned(const Bureaucrat& Bureaucrat){
    if (Bureaucrat.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Grade is too high.";
}
const char *Form::GradeTooLowException::what() const throw(){
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& output, const Form& obj){
    output << "name: " << obj.getName() << "   is signed: " << obj.getIsSigned()
            << "   signGrade: " << obj.getSignGrade() << "   execGrade: " << obj.getExecGrade();
    return output;
}
