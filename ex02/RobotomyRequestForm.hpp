#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    protected:

    public:
        //Constructors
        RobotomyRequestForm(const std::string& target);

        //Copy Constructor
        RobotomyRequestForm(const RobotomyRequestForm& other);

        //Destructor
        ~RobotomyRequestForm();

        //Copy assignment operator
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);


        virtual void    executeAction() const;

};

#endif