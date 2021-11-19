#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form(target, 72, 45)
{}

//copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
: Form(src)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=
(RobotomyRequestForm const & src)
{
    if(this != &src)
        *this = src;
    return *this;
}
 void   RobotomyRequestForm::execute(Bureaucrat const & executor) const
 {
    if (!get_is_signed())
    {
       std::cout<< get_form_name() << " is not signed" << std::endl;
       return;
    }
    if (executor.getGrade() > get_grade_to_exe())
    {
        throw Bureaucrat::GradeTooLowException();
        return;
    }
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return;
 }