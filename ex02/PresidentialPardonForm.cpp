#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form(target, 25, 5)
{}

//copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
: Form(src)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=
(PresidentialPardonForm const & src)
{
    if(this != &src)
        *this = src;
    return *this;
}
 void   PresidentialPardonForm::execute(Bureaucrat const & executor) const
 {
    if (!get_is_signed())
    {
       std::cout<< get_form_name() << " is not signed" << std::endl;
       return;
    }
    if (executor.getGrade() > get_grade_to_exe())
    {
        throw Form::GradeTooLowException();
        return;
    }
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return;
 }