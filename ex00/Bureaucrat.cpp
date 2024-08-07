#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
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
    {
        _grade = other._grade;
        _name = other._name;
    }
    return *this;
}
