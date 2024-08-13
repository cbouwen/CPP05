#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    _isSigned = false;
    std::cout << "Default constructor called!" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called!" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Copy constructor called!" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if(this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

//Getters
const std::string&  Form::getName() const
{
    return _name;
}

bool    Form::getSigned() const
{
    return _isSigned;
}

int   Form::getSignGrade() const
{
    return  _signGrade;
}

int   Form::getExecGrade() const
{
    return _execGrade;
}

//Functions


void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > getSignGrade())
        throw GradeTooLowException();
    else
        _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& b) 
{
    os << "Form " << b.getName() << ", sign state:  " << b.getSigned() << ". Grade required to sign: " << b.getSignGrade() << ". Grade required to execute: " << b.getExecGrade() << std::endl;
    return os;
}