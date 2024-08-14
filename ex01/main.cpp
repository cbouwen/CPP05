#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try 
    {
        Bureaucrat a("Bob", 1);
        Bureaucrat b("Gerald", 126);
        Bureaucrat fired("Tommy", 150);

        Form standard("Standard", 150, 140);
        Form highExec("High", 30, 10);
        Form classified("Classified", 3, 1);
        //Form faulty("Faulty", 151, 0); //  Comment this back in to test the exception at the bottom of the main. This will skip all following code.
    
        // Testing Form signing
        a.signForm(standard); // Bob can sign because his grade (1) is <= 150
        b.signForm(highExec); // Gerald cannot sign because his grade (126) is > 30
        a.signForm(classified); // Bob can sign because his grade (1) is <= 3

        try 
        {
            fired.signForm(standard);
        } 
        catch (const Form::GradeTooLowException& e) 
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