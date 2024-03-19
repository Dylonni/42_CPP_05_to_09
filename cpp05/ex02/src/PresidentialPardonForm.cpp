/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:40 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 01:25:07 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN "[PresidentialPardonForm] Destructor called" RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << CYAN "Default [PresidentialPardonForm] constructor called" RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
AForm("Presidential Pardon Form", _reqSign, _reqExec), _target(target)
{
	std::cout << CYAN "Parameterized [PresidentialPardonForm] constructor called" RESET << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) :
AForm(ref), _target(ref._target)
{
	std::cout << CYAN "Copy [PresidentialPardonForm] constructor called" RESET << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	std::cout << CYAN "Assignation [PresidentialPardonForm] constructor called" RESET << std::endl;
	this->_target = ref._target;
	return (*this);
}

void	PresidentialPardonForm::beExecuted() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}

const std::string&	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}