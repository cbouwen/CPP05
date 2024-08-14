#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    _isSigned = false;
    std::cout << "Default constructor called!" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Destructor called!" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Copy constructor called!" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    if(this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

//Getters
const std::string&  AForm::getName() const
{
    return _name;
}

bool    AForm::getSigned() const
{
    return _isSigned;
}

int   AForm::getSignGrade() const
{
    return  _signGrade;
}

int   AForm::getExecGrade() const
{
    return _execGrade;
}

//Functions


void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > getSignGrade())
        throw GradeTooLowException();
    else
        _isSigned = true;
}


void    AForm::execute(Bureaucrat const & executor) const
{
    if (!getSigned())
        throw NotSigned();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    executeAction();
}


std::ostream& operator<<(std::ostream& os, const AForm& b) 
{
    os << "AForm " << b.getName() << ", sign state:  " << b.getSigned() << ". Grade required to sign: " << b.getSignGrade() << ". Grade required to execute: " << b.getExecGrade() << std::endl;
    return os;
}