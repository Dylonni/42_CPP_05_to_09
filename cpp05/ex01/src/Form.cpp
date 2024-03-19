/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:48 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 15:52:49 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::~Form()
{
	std::cout << CYAN "[Form] Destructor called" RESET << std::endl;
	return ;
}

Form::Form(void) : _name("Default Form"), _reqSign(150), _reqExec(150), _isSigned(false)
{
	std::cout << CYAN "Default [Form] constructor called" RESET << std::endl;
	return ;
}

Form::Form(const std::string& name, const int reqSign, const int reqExec) : _name(name),
_reqSign(reqSign), _reqExec(reqExec), _isSigned(false)
{
	std::cout << CYAN "Parameterized [Form] constructor called" RESET << std::endl;
	if (reqSign < 1 || reqExec < 1 )
		throw (Form::GradeTooHighException());
	if (reqSign > 150 || reqExec > 150)
		throw (Form::GradeTooLowException());
	return ;
}

Form::Form(const Form& ref) : _name(ref._name), _reqSign(ref._reqSign),
_reqExec(ref._reqExec), _isSigned(false)
{
	std::cout << CYAN "Copy [Form] constructor called" RESET << std::endl;
	return ;
}

Form&	Form::operator=(const Form& ref)
{
	std::cout << CYAN "Assignation [Form] constructor called" RESET << std::endl;
	this->_isSigned = ref._isSigned;
	return (*this);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_reqSign)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLowException());
	return ;
}

const std::string&	Form::getName() const
{
	return (this->_name);
}

int	Form::getReqSign() const
{
	return (this->_reqSign);
}
int	Form::getReqExec() const
{
	return (this->_reqExec);
}

bool	Form::getStatus() const
{
	return (this->_isSigned);
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high for this form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low for this form.");
}

std::ostream&	operator<<(std::ostream& os, Form const& rhs)
{
	os << "\"" << rhs.getName() << "\" | has been signed : " 
		<< std::boolalpha <<  rhs.getStatus() << "\n"
		<< "Required to sign: " << rhs.getReqSign()
		<< " | Required to exec: " << rhs.getReqExec() << std::endl;
	return (os);
}
