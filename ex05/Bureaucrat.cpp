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
    if(_grade < 1)
    throw Bureaucrat::GradeTooHighException();
    if(_grade > 150)
    throw Bureaucrat::GradeTooLowException();
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
std::string Bureaucrat::getName()
{
    return _name;
};

int Bureaucrat::getGrade()
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


//== '<<' overload==
std::ostream& operator<<(std::ostream &out, Bureaucrat &bureau)
{
    std::cout << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
    return out;
}