/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:36:58 by alallema          #+#    #+#             */
/*   Updated: 2018/04/03 00:06:24 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeSig, int gradeEx) : _name(name), _isSigned(false), _gradeSig(gradeSig), _gradeEx(gradeEx) {
	if (gradeSig < 1 || gradeEx < 1)
		throw Form::GradeTooHighException();
	else if (gradeSig > 150 || gradeEx > 150)
		throw Form::GradeTooLowException();
	else {}
	return;
}

Form::Form(Form const & src) : _name(src.getName()), _gradeSig(src.getGradeSig()), _gradeEx(src.getGradeEx()){
	*this = src;
	return;
}

Form::~Form(void) {
	return;
}

Form &			Form::operator=(Form const & rhs){
	this->_isSigned = rhs.getSigned();
	return (*this);
}

std::string		Form::getName() const{
	return(this->_name);
}

int				Form::getGradeSig() const{
	return(this->_gradeSig);
}

int				Form::getGradeEx() const{
	return(this->_gradeEx);
}

bool			Form::getSigned() const{
	return(this->_isSigned);
}

void			Form::setSigned(bool isSigned){
	this->_isSigned = isSigned;
	return ;
}

void			Form::beSigned(Bureaucrat & src){
	if (!this->_isSigned)
		src.signForm(*this);
	else
		std::cout << this->getName() << " is already sign." << std::endl;
	return ;
}

std::ostream &		operator<<(std::ostream & o, Form const & rhs) {
	o << rhs.getName() << ", Form " << rhs.getSigned() << std::endl;
	return(o);
}

Form::GradeTooHighException::GradeTooHighException() throw(){
//	std::cout << "Form Too High Exception" << std::endl;
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) throw(){
	*this = src;
	return;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){
	return;
}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(GradeTooHighException const & rhs){
	(void)rhs;
	return (*this);
}

Form::GradeTooLowException::GradeTooLowException() throw(){
//	std::cout << "Form Too Low Exception" << std::endl;
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) throw(){
	*this = src;
	return;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
	return;
}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(GradeTooLowException const & rhs){
	(void)rhs;
	return (*this);
}
