#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Form;
#include "Bureaucrat.hpp"

class Form
{
    public:
        //==CONSTRUCTERS==
        //default
        Form();
        //with name
        Form(std::string name, int grade_to_sign, int grade_to_exe);
        //copy constructor
        Form(Form &src);
        //==DESTRUCTOR==
        ~Form();
        //==assignation overload==
        Form& operator=(Form &src);
        //==GETTERS==
        std::string get_form_name();
        bool        get_is_signed();
        int         get_grade_to_sign();
        int         get_grade_to_exe();
        //==SETTERS==
        //==UNIQUE FUNCS==
        void    beSigned(Bureaucrat &breaucrat);
        class GradeTooHighException:public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException:public std::exception
        {
            const char* what() const throw();
        };
    private:
        std::string const   _form_name;
        bool                _is_signed;
        int         const   _grade_to_sign;
        int         const   _grade_to_exe;
};

//== '<<' overload==
std::ostream& operator<<(std::ostream &out, Form &Form);

#endif
