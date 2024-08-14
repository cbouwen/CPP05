#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    protected:

    public:
        //Constructors
        Bureaucrat();
        Bureaucrat(std::string name, int grade);

        //Copy Constructor
        Bureaucrat(const Bureaucrat& other);

        //Destructor
        ~Bureaucrat();

        //Copy assignment operator
        Bureaucrat& operator=(const Bureaucrat& other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low!";
                }
        };

        //Getters
        int                 getGrade() const;
        const std::string&  getName() const;

        //Functions
        void    increaseGrade();
        void    decreaseGrade();
        void    signForm(AForm &b);
        void    executeForm(AForm const & form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif  