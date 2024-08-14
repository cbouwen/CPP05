#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <string>

class   Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    protected:
    
    public:
        //Constructors
        AForm(const std::string name, const int signGrade, const int execGrade); 

        //Copy Constructor
        AForm(const AForm& other);

        //Destructor
        virtual ~AForm();

        //Copy assignment operator
        AForm& operator=(const AForm& other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high to sign this AForm!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low to sign this AForm!";
                }
        };

        class NotSigned : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form is not signed yet!";
                }
        };

        //Getters
        const std::string&  getName() const;
        bool          getSigned() const;
        int           getSignGrade() const;
        int           getExecGrade() const;

        void    beSigned(Bureaucrat& b);
        void            execute(Bureaucrat const & executor) const;
        virtual void            executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);



#endif