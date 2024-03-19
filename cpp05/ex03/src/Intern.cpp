/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:28:03 by daumis            #+#    #+#             */
/*   Updated: 2024/02/28 04:14:17 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
# include "../include/PresidentialPardonForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"

Intern::~Intern(void)
{
	std::cout << CYAN "[Intern] Destructor called" RESET << std::endl;
	return ;
}

Intern::Intern(void)
{
	std::cout << CYAN "Default [Intern] constructor called" RESET << std::endl;
	return ;
}

Intern::Intern(const Intern& ref)
{
	std::cout << CYAN "Copy [Intern] constructor called" RESET << std::endl;
	(void)ref;
	return ;
}

Intern&	Intern::operator=(const Intern& ref)
{
	std::cout << CYAN "Assignation [Intern] constructor called" RESET << std::endl;
	(void)ref;
	return (*this);
}

static AForm*	createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ("Name is invalid");
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	AForm*	toCreate = NULL;
	static const t_formList	forms[3] =
	{
		{"Presidential pardon form", createPresidentialPardonForm},
		{"Robotomy request form", createRobotomyRequestForm},
		{"Shrubbery creation form", createShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == formName)
		{
			toCreate= forms[i].func(target);
			std::cout << GREEN "Intern creates " << toCreate->getName() << RESET << std::endl;
			return (toCreate);
		}
	}
	std::cout << RED "Intern couldn't create form \"" << formName << "\" " RESET;
	throw Intern::InvalidFormName();
}
