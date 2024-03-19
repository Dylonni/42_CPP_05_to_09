/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/02/28 01:45:11 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	/*Objects init*/
	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat righthand("rightHand", 2);
	std::cout << righthand << std::endl;
	Bureaucrat bureaucrat2("bureaucrat2", 145);
	std::cout << bureaucrat2 << std::endl;
	PresidentialPardonForm	pForm("Mike");
	std::cout << pForm << std::endl;
	RobotomyRequestForm	rForm("Elise");
	std::cout << rForm << std::endl;
	RobotomyRequestForm	rForm2("Dali");
	std::cout << rForm2 << std::endl;
	ShrubberyCreationForm sForm("Nat");
	std::cout << sForm << std::endl;

	/*Main tests*/
	std::cout << YELLOW "Attempt to sign pForm by [" << boss.getName() << "]" RESET << std::endl;
	boss.signForm(pForm);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute pForm by [" << boss.getName() << "]" RESET << std::endl;
	boss.executeForm(pForm);
	std::cout << std::endl;

	/*Same test with righthand*/
	std::cout << YELLOW "Attempt to sign rForm by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.signForm(rForm);
	righthand.signForm(rForm2);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute rForm by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.executeForm(rForm);
	righthand.executeForm(rForm2);
	std::cout << std::endl;

	/*Same test with bureaucrat2*/
	std::cout << YELLOW "Attempt to sign sForm by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.signForm(sForm);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute sForm by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.executeForm(sForm);
	std::cout << std::endl;

	/*After it's been signed by boss*/
	std::cout << YELLOW "Attempt to sign sForm by [" << boss.getName() << "]" RESET << std::endl;
	boss.signForm(sForm);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute sForm by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.executeForm(sForm);
	std::cout << std::endl;
	return (0);
}
