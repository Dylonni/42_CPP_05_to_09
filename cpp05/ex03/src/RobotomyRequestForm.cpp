/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:22 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 02:59:28 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN "[RobotomyRequestForm] Destructor called" RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << CYAN "Default [RobotomyRequestForm] constructor called" RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
AForm("Robotomy Request Form", _reqSign, _reqExec), _target(target)
{
	std::cout << CYAN "Parameterized [RobotomyRequestForm] constructor called" RESET << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) :
AForm(ref), _target(ref._target)
{
	std::cout << CYAN "Copy [RobotomyRequestForm] constructor called" RESET << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	std::cout << CYAN "Assignation [RobotomyRequestForm] constructor called" RESET << std::endl;
	this->_target = ref._target;
	return (*this);
}

void	RobotomyRequestForm::beExecuted() const
{
	std::cout << " Beep boop.. (Drill NOISES ~)  - Joining the glorious evolution... 🔧" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized! 🤖" << std::endl;
	else
		std::cout << this->_target << " couldn't be robotomized ❌" << std::endl;
	return ;
}

const std::string&	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}
