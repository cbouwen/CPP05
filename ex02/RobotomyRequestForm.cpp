#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :AForm("Robotomy Request Form", 72, 45)
{
    _target = target;
    std::cout << "RobotomyRequestForm created for " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    std::cout << "Copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

void    RobotomyRequestForm::executeAction() const
{
    static int  i;

    i++;
    std::cout << "BZZZZZZZZZZZZZZZZZZZZ" << std::endl;
    if (i % 2 == 0)
        std::cout << _target << " has been sucessfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy has failed. Unfortunate." << std::endl;
}