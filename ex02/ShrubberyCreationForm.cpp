#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :AForm("Shrubbery Creation Form", 145, 137)
{
    _target = target;
    std::cout << "ShrubberyCreationForm created for " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    std::cout << "Copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Error creating file: " << _target + "_shrubbery" << std::endl;
        return;
    }

    file << "        _\n";
    file << "      _/\\_ \n";
    file << "     /    \\ \n";
    file << "    /______\\ \n";
    file << "      ||||\n";
    file << "      ||||\n";

    file.close();
    std::cout << "Shrubbery created in file: " << _target + "_shrubbery" << std::endl;
}
