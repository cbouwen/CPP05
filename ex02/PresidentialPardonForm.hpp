#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    protected:
    
    public:
        //Constructors
        PresidentialPardonForm(const std::string& target);

        //Copy Constructor
        PresidentialPardonForm(const PresidentialPardonForm& other);

        //Destructor
        ~PresidentialPardonForm();

        //Copy assignment operator
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);


        virtual void    executeAction() const;
};

#endif