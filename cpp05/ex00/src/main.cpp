/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 01:14:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat bureaucrat2("bureaucrat2", 149);
	std::cout << bureaucrat2 << std::endl;
	Bureaucrat basic;
	std::cout << basic << std::endl;
	/*HIGHER BUREAUCRAT TEST*/
	try
	{
		std::cout << "Trying to create higher rank bureaucrat"<< std::endl;
		Bureaucrat higherbureaucrat("higher", 0);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	/*LOWER BUREAUCRAT TEST*/
	try
	{
		std::cout << "Trying to create lower rank bureaucrat"<< std::endl;
		Bureaucrat lowerbureaucrat("lower", 151);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	/*Main bloc*/
	try
	{
		std::cout << YELLOW "Decrementing Boss to a lower level " RESET << std::endl;
        boss.decrementGrade();
		std::cout << boss << std::endl;
		std::cout << YELLOW "Decrementing bureaucrat2 to a lower level " RESET << std::endl;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	/*Same Test*/
	try
	{
		std::cout << YELLOW "Decrementing Boss to a lower level " RESET << std::endl;
        boss.decrementGrade();
		std::cout << boss << std::endl;
		std::cout << YELLOW "Decrementing bureaucrat2 to a lower level " RESET << std::endl;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	return (0);
}
