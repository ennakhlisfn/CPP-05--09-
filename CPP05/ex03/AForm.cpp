#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()) {}

AForm& AForm::operator=(const AForm& other){
    if(this == &other) return *this;

    _isSigned = other.getIsSigned();
    return *this;
}

std::string AForm::getName() const{
    return _name;
}
bool AForm::getIsSigned() const{
    return _isSigned;
}
int AForm::getSignGrade() const{
    return _signGrade;
}
int AForm::getExecGrade() const{
    return _execGrade;
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high.";
}
const char *AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low.";
}
const char *AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed.";
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << form.getSignGrade()
       << ", exec grade: " << form.getExecGrade();
    return os;
}