#include "Bureaucrat.hpp"

//==CONSTRUCTERS==
//default
Form::Form()
:_form_name(""),
_is_signed(0),
_grade_to_sign(0),
_grade_to_exe(0)
{};
//with name
Form::Form(std::string form_name, int grade_to_sign, int grade_to_exe)
:_form_name(form_name),
_is_signed(0),
_grade_to_sign(grade_to_sign),
_grade_to_exe(grade_to_exe)
{
    if(get_grade_to_sign() < 1 || get_grade_to_exe() < 1)
        throw Bureaucrat::GradeTooHighException();
    if(get_grade_to_sign() > 150 || get_grade_to_exe() > 150)
        throw Bureaucrat::GradeTooLowException();
}
//copy constructor
Form::Form(Form const &src)
:_form_name(src._form_name),
_is_signed(src._is_signed),
_grade_to_sign(src._grade_to_sign),
_grade_to_exe(src._grade_to_exe)
{}
//==DESTRUCTOR==
Form::~Form()
{}
//==assignation overload==
Form& Form::operator=(Form &src)
{
    _is_signed = src._is_signed;
    return *this;
};
//==GETTERS==
std::string Form::get_form_name() const
{return _form_name;};
bool        Form::get_is_signed() const
{return _is_signed;};
int         Form::get_grade_to_sign() const
{return _grade_to_sign;};
int         Form::get_grade_to_exe() const
{return _grade_to_exe;};
//==SETTERS==
//==UNIQUE FUNCS==
void    Form::beSigned(Bureaucrat &breaucrat)
{
    if(breaucrat.getGrade() < get_grade_to_sign())
        _is_signed = 1;
    else
        throw Bureaucrat::GradeTooLowException();
};


const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

//== '<<' overload==
std::ostream& operator<<(std::ostream &out, Form &form)
{
    std::cout << "name of form : " << form.get_form_name() << std::endl;
    std::cout << "is signed ?: ";
    if(form.get_is_signed() == 1)
        std::cout<<"yes"<<std::endl;
    else
        std::cout<<"no"<<std::endl;
    std::cout << "To sign this form, you need : " << form.get_grade_to_sign() << std::endl;
    std::cout << "To execute this form, you need : " << form.get_grade_to_exe() << std::endl;
    return out;
};