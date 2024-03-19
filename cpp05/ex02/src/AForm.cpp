/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:48 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 22:52:54 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::~AForm()
{
	std::cout << CYAN "[AForm] Destructor called" RESET << std::endl;
	return ;
}

AForm::AForm(void) : _name("Default AForm"), _reqSign(150), _reqExec(150), _isSigned(false)
{
	std::cout << CYAN "Default [AForm] constructor called" RESET << std::endl;
	return ;
}

AForm::AForm(const std::string& name, const int reqSign, const int reqExec) : _name(name),
_reqSign(reqSign), _reqExec(reqExec), _isSigned(false)
{
	std::cout << CYAN "Parameterized [AForm] constructor called" RESET << std::endl;
	if (reqSign < 1 || reqExec < 1 )
		throw (AForm::GradeTooHighException());
	if (reqSign > 150 || reqExec > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::AForm(const AForm& ref) : _name(ref._name), _reqSign(ref._reqSign),
_reqExec(ref._reqExec), _isSigned(false)
{
	std::cout << CYAN "Copy [AForm] constructor called" RESET << std::endl;
	return ;
}

AForm&	AForm::operator=(const AForm& ref)
{
	std::cout << CYAN "Assignation [AForm] constructor called" RESET << std::endl;
	this->_isSigned = ref._isSigned;
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getReqSign() const
{
	return (this->_reqSign);
}
int	AForm::getReqExec() const
{
	return (this->_reqExec);
}

bool	AForm::getStatus() const
{
	return (this->_isSigned);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_reqSign)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
	return ;
}

void	AForm::execute(const Bureaucrat& executor) const
{	
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());
	if (executor.getGrade() <= this->_reqExec)
		this->beExecuted();
	else
		throw (AForm::GradeTooLowException());
	return ;
	
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high for this form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low for this form.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("This form has not been signed.");
}

std::ostream&	operator<<(std::ostream& os, AForm const& rhs)
{
	os << "\"" << rhs.getName() << "\" | has been signed : " 
		<< std::boolalpha <<  rhs.getStatus() << "\n"
		<< "Required to sign: " << rhs.getReqSign()
		<< " | Required to exec: " << rhs.getReqExec() << std::endl;
	return (os);
}
