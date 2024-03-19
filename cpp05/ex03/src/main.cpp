/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/02/28 04:13:19 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
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
	Intern intern1;
	Intern intern2;
	Intern intern3;
	AForm* created_by_intern1;
	AForm* created_by_intern2;
	AForm* another_created_by_intern2 = NULL;
	AForm* created_by_intern3;
	AForm* another_form;
	created_by_intern1 = intern1.makeForm("Presidential pardon form", "Daniel");
	created_by_intern2 = intern2.makeForm("Robotomy request form", "Richard");
	another_created_by_intern2 = intern2.makeForm("Robotomy request form", "Louis");
	created_by_intern3 = intern3.makeForm("Shrubbery creation form", "Lise");
	
	/*Main tests*/
	std::cout << YELLOW "Attempt to sign Presidential Form by [" << boss.getName() << "]" RESET << std::endl;
	boss.signForm(*created_by_intern1);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute  Presidential Form by [" << boss.getName() << "]" RESET << std::endl;
	boss.executeForm(*created_by_intern1);
	std::cout << std::endl;

	/*Same test with righthand*/
	std::cout << YELLOW "Attempt to sign Robotomy Form by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.signForm(*created_by_intern2);
	righthand.signForm(*another_created_by_intern2);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute Robotomy Form by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.executeForm(*created_by_intern2);
	righthand.executeForm(*another_created_by_intern2);
	std::cout << std::endl;

	/*Same test with bureaucrat2*/
	std::cout << YELLOW "Attempt to sign Shrubbery Form by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.signForm(*created_by_intern3);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute Shrubbery Form by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.executeForm(*created_by_intern3);
	std::cout << std::endl;

	/*After it's been signed by boss*/
	std::cout << YELLOW "Attempt to sign Shrubbery Form by [" << boss.getName() << "]" RESET << std::endl;
	boss.signForm(*created_by_intern3);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to execute Shrubbery Form by [" << bureaucrat2.getName() << "]" RESET << std::endl;
	bureaucrat2.executeForm(*created_by_intern3);
	std::cout << std::endl;
	delete (created_by_intern1);
	delete (created_by_intern2);
	delete (another_created_by_intern2);
	delete (created_by_intern3);

	/*With a form that doesnt work*/
	try
	{
		another_form = intern1.makeForm("LOLOLOL", "lilili");
	}
	catch(Intern::InvalidFormName& e)
	{
		std::cout << RED ": " << e.what() << RESET << std::endl;
	}
	return (0);
}
