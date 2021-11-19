#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5){
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src){
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

PresidentialPardonForm &			PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	if(this != &rhs)
		*this = rhs;
	return (*this);
}

void					PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!this->get_is_signed()){
		std::cout << "Form " << this->get_form_name() <<" not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > this->get_grade_to_exe()){
		throw Form::GradeTooHighException();
		return;
	}
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return;
}


// #include "PresidentialPardonForm.hpp"

// //==CONSTRUCTERS==
// //default
// PresidentialPardonForm::PresidentialPardonForm()
// {};
// //with name
// PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
// {;}
// //copy constructor
// PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm   &src)
// :Form(src)
// {
//     *this = src;
// };
// //==DESTRUCTOR==
// PresidentialPardonForm::~PresidentialPardonForm()
// {};
// //==assignation overload==
// PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
// {
// 	if(this != &src)
// 		*this = src;
// 	return (*this);

// };
// //==GETTERS==
// //==SETTERS==
// //==UNIQUE FUNCS==
// void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
// {
// 	if (!get_is_signed()){
// 		std::cout << "Form " << get_form_name() <<" not signed" << std::endl;
// 		return;
// 	}
// 	if (executor.getGrade() > get_grade_to_exe()){
// 		throw Form::GradeTooHighException();
// 		return;
// 	}
// 	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
// 	return;

// };
