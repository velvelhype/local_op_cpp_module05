#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
    public:
        //qon_with_name
        RobotomyRequestForm(std::string target);
        //copi_qon
        RobotomyRequestForm(RobotomyRequestForm const & src);
        //must overlode
        virtual void execute(Bureaucrat const & executor) const;
        //destructor
        virtual ~RobotomyRequestForm(void);
        //assign
	    RobotomyRequestForm &operator=
        (RobotomyRequestForm const & rhs);
    private:
        //defqon
        RobotomyRequestForm();

};

#endif
