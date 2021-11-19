#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
    public:
        //qon_with_name
        PresidentialPardonForm(std::string target);
        //copi_qon
        PresidentialPardonForm(PresidentialPardonForm const & src);
        //must overlode
        virtual void execute(Bureaucrat const & executor) const;
        //destructor
        virtual ~PresidentialPardonForm(void);
        //assign
	    PresidentialPardonForm &operator=
        (PresidentialPardonForm const & rhs);
    private:
        //defqon
        PresidentialPardonForm();

};

#endif
