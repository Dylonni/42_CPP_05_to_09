/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:05 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 02:59:52 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN "[ShrubberyCreationForm] Destructor called" RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << CYAN "Default [ShrubberyCreationForm] constructor called" RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
AForm("Shrubbery Creation Form", _reqSign, _reqExec), _target(target)
{
	std::cout << CYAN "Parameterized [ShrubberyCreationForm] constructor called" RESET << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) :
AForm(ref), _target(ref._target)
{
	std::cout << CYAN "Copy [ShrubberyCreationForm] constructor called" RESET << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	std::cout << CYAN "Assignation [ShrubberyCreationForm] constructor called" RESET << std::endl;
	this->_target = ref._target;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted() const
{
	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::_tree;
		std::cout << "🌲 created in : " << _target << "_shrubbery." << std::endl;
		ofs.close();
	}
	return ;
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

const std::string	ShrubberyCreationForm::_tree =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";
