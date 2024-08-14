#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Default constructor called!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor called!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        _grade = other._grade;
    return *this;
}

//Functions
int    Bureaucrat::getGrade() const
{
    return (_grade);
}

const std::string&   Bureaucrat::getName() const
{
    return (_name);
}

void    Bureaucrat::increaseGrade()
{
    if (_grade > 1)
        _grade--;
    else
        std::cout << "Grade can't get any higher. Promote him!" << std::endl;
}

void    Bureaucrat::decreaseGrade()
{
    if (_grade < 150)
        _grade++;
    else
        std::cout << "Grade can't get any lower. Fire him already.." << std::endl;
}

void    Bureaucrat::signForm(AForm &b)
{
    try
    {
        b.beSigned(*this);
        std::cout << _name << " signed AForm " << b.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
            std::cout << _name << " couldn't sign " << b.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    std::cout << getName() << " executed " << form.getName() << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
