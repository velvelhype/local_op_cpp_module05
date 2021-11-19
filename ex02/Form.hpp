/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:37:00 by alallema          #+#    #+#             */
/*   Updated: 2018/04/03 02:41:41 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

public:
	Form(std::string name, int gradeSig, int gradeEx);
	Form(Form const & src);
	virtual ~Form(void);

	Form &				operator=(Form const & rhs);
	std::string			getName(void) const;
	int					getGradeSig(void) const;
	int					getGradeEx(void) const;
	bool				getSigned(void) const;
	void				setSigned(bool isSigned);
	void				beSigned(Bureaucrat & src);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception{

	public:
		GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const & src) throw();
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException& operator=(GradeTooHighException const & rhs);
	};

	class GradeTooLowException : public std::exception{

	public:
		GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const & src) throw();
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException& operator=(GradeTooLowException const & rhs);
	};
protected:
	Form(void);

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeSig;
	int const			_gradeEx;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
