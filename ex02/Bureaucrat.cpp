#include "Bureaucrat.hpp"

//==CONSTRUCTERS==
//default
Bureaucrat::Bureaucrat()
{};
//with name and grade
Bureaucrat::Bureaucrat(std::string name, int grade)
:_name(name),
_grade(grade)
{
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(_grade > 150)
        throw Bureaucrat::GradeTooLowException();
};
//copy constructor
Bureaucrat::Bureaucrat(Bureaucrat &src)
:_name(src._name),
_grade(src._grade)
{
};
//==DESTRUCTOR==
Bureaucrat::~Bureaucrat()
{};
//== '=' overload==
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    this->_grade = src._grade;
    return (*this);
};

//==GETTERS==
std::string Bureaucrat::getName() const
{
    return _name;
};

int Bureaucrat::getGrade() const
{
    return _grade;
};
//==SETTERS==

//==UNIQUE FUNCS==
void Bureaucrat::incrementGrade()
{
    if(_grade <= 1)
        throw Bureaucrat::GradeTooHighException();

    _grade--;
};
void Bureaucrat::decrementGrade()
{
    if(_grade >= 150)
        throw Bureaucrat::GradeTooLowException();

    _grade++;
};

//exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Exeption: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Exeption: Grade is too low";
}

void    Bureaucrat::signForm(Form &form)
{
    if(form.get_is_signed())
    {
        std::cout << getName() << " can't sign" << form.get_form_name();
        std::cout << " because it is already signed" << std::endl;
    }
    else if(form.get_grade_to_sign() <= getGrade())
    {
        std::cout << getName() << " can't sign " << form.get_form_name();
        std::cout << " because of low grade" << std::endl;
    }
    else
    {
        std::cout << getName() << " signed " << form.get_form_name() << std::endl;
    }
    form.beSigned(*this);
};

//== '<<' overload==
std::ostream& operator<<(std::ostream &out, Bureaucrat &bureau)
{
    std::cout << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
    return out;
}