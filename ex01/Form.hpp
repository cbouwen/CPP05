#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class   Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    protected:
    
    public:
        //Constructors
        Form(const std::string name, const int signGrade, const int execGrade); 

        //Copy Constructor
        Form(const Form& other);

        //Destructor
        ~Form();

        //Copy assignment operator
        Form& operator=(const Form& other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high to sign this form!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low to sign this form!";
                }
        };

        //Getters
        const std::string&  getName() const;
        bool          getSigned() const;
        int           getSignGrade() const;
        int           getExecGrade() const;

        void    beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& b);



#endif