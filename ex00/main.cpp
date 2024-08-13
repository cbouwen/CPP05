#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat  a("Bob", 1);
    Bureaucrat  b("Gerald", 126);
    Bureaucrat  fired("Tommy", 150);

    std::cout << a << std::endl;
    a.increaseGrade();
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    b.decreaseGrade();
    std::cout << b << std::endl;

    try 
    {
        Bureaucrat cheater("Bob", 0);
    } 
    catch (const Bureaucrat::GradeTooHighException& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooLowException& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat slacker("John", 151);
    } 
    catch (const Bureaucrat::GradeTooHighException& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooLowException& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << fired << std::endl;
    fired.decreaseGrade();
    std::cout << fired << std::endl;

}