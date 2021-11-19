/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:55:08 by alallema          #+#    #+#             */
/*   Updated: 2018/04/03 03:42:59 by alallema         ###   ########.fr       */
/*                                                                            */
/*o ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name (name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else {}
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()){
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	return;
}

Bureaucrat &			Bureaucrat::operator=(Bureaucrat const & rhs){
	this->_grade = rhs.getGrade();
	return (*this);
}

std::string			Bureaucrat::getName() const{
	return(this->_name);
}

int					Bureaucrat::getGrade() const{
	return(this->_grade);
}

void				Bureaucrat::upGrade(void){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else {
  	this->_grade -= 1;
	}
	return ;
}

void				Bureaucrat::downGrade(void){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else {
  	this->_grade += 1;
	}
	return ;
}

void				Bureaucrat::signForm(Form& form){
	if (this->_grade <= form.getGradeSig()){
		std::cout << this->_name << " signs " << form.getName() << std::endl;
		form.setSigned(true);
	}
	else
		std::cout << this->_name << " cannot sign because " << form.getName() << " need to be grade " << form.getGradeSig() << std::endl;
	return ;
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return(o);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw(){
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) throw(){
	*this = src;
	return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){
	return;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs){
	(void)rhs;
	return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw(){
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) throw(){
	*this = src;
	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){
	return;
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs){
	(void)rhs;
	return (*this);
}

void		Bureaucrat::executeForm(Form const & form) const{
	if (this->getGrade() <= form.getGradeEx())
	{
		std::cout << this->_name << " executes " << form;
		form.execute(*this);
	}
	else
		std::cout << "Cannot execute form because the bureaucrat's grade is too low.";
	return;
}
