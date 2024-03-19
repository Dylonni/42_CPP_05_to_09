/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:28 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 15:52:55 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void)
{
	std::cout << CYAN "[Bureaucrat] Destructor called" RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << CYAN "Default [Bureaucrat] constructor called" RESET << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, int	grade) : _name(name), _grade(grade)
{
	std::cout << CYAN "Parameterized [Bureaucrat] constructor called" RESET << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
{
	std::cout << CYAN "Copy [Bureaucrat] constructor called" RESET << std::endl;
	*this = ref;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << CYAN "Assignation [Bureaucrat] constructor called" RESET << std::endl;
	if (this != &ref)
        this->_grade = ref._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << RED << this->getName() << " couldn't sign \"" << form.getName() << "\" because: " << e.what() << RESET << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade can't be set this high, it must be within range [1;150]\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade can't be set this low, it must be within range [1;150]\n");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs)
{
    os << "Bureaucrat Name: " << rhs.getName() << " | grade: " << rhs.getGrade() << std::endl;
    return (os);
}
