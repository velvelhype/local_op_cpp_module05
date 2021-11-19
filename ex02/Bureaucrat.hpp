#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
  public:
        //==CONSTRUCTERS==
        //default
        Bureaucrat();
        //with name and grade
        Bureaucrat(std::string name, int grade);
        //copy constructor
        Bureaucrat(Bureaucrat &src);
        //==DESTRUCTOR==
        ~Bureaucrat();
        //== '=' overload==
        Bureaucrat& operator=(const Bureaucrat& src);
        //==GETTERS==
        //getName
        std::string getName() const;
        //getGrade
        int getGrade() const;
        //==SETTERS==
        //setGrade
        void set_grade(int v);
        //==UNIQUE FUNCS==
        //incrementGrade
        void incrementGrade();
        //decrementGrade
        void decrementGrade();
        //exceptions
        class GradeTooHighException:public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
            const char* what() const throw();
        };
        void    signForm(Form &form);
    private:
        std::string const _name;
        int         _grade;
};

//== '<<' overload==
std::ostream& operator<<(std::ostream &out, Bureaucrat &bureau);

#endif