#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    try 
    {
        Bureaucrat bob("Bob", 1);        
        Bureaucrat gerald("Gerald", 50); 
        Bureaucrat tommy("Tommy", 150);  

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("criminal");

        // Test signing and executing ShrubberyCreationForm
        {
            bob.signForm(shrubbery);       // Bob can sign because his grade (1) <= 145
            bob.executeForm(shrubbery);    // Bob can execute because his grade (1) <= 137
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test signing and executing RobotomyRequestForm
        try
        {
            gerald.signForm(robotomy);      // Gerald can sign because his grade (50) <= 72
            gerald.executeForm(robotomy);   // Gerald can execute because his grade (50) <= 45
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test signing and executing PresidentialPardonForm
        try
        {
            tommy.signForm(pardon);         // Tommy cannot sign because his grade (150) > 25
            tommy.executeForm(pardon);      // Tommy cannot execute because his grade (150) > 5
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Further testing of exceptions and error handling
        try 
        {
            Bureaucrat lowRank("LowRank", 151); // Invalid bureaucrat grade
            lowRank.signForm(shrubbery);        // Will throw GradeTooLowException
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try 
        {
            Bureaucrat lowRank("LowRank", 151); // Invalid bureaucrat grade
            lowRank.executeForm(shrubbery);     // Will throw GradeTooLowException
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
