#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    protected:

    public:
        //Constructors
        ShrubberyCreationForm(const std::string& target);

        //Copy Constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& other);

        //Destructor
        ~ShrubberyCreationForm();

        //Copy assignment operator
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        virtual void    executeAction() const;

};

#endif