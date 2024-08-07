#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    protected:

    public:
        //Constructors
        Bureaucrat();

        //Copy Constructor
        Bureaucrat(const Bureaucrat& other);

        //Destructor
        ~Bureaucrat();

        //Copy assignment operator
        Bureaucrat& operator=(const Bureaucrat& other);

        //Getters
        const int           getGrade();
        const std::string   getName();

        //Setters
        void                setGrade(const int &input);
        void                setName(const std::string   &input);

        void                increaseGrade();
        void                decreaseGrade();

};

#endif  