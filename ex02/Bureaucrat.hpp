/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:22:41 by alallema          #+#    #+#             */
/*   Updated: 2018/04/03 02:41:50 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "Form.hpp"

class	PresidentialPardonForm : public Form{

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm &			operator=(PresidentialPardonForm const & rhs);
	virtual void					execute(Bureaucrat const & executor) const;

private:
	PresidentialPardonForm(void);
};

#endif
