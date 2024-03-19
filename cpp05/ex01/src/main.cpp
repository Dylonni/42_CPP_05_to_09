/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 15:52:38 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	Bureaucrat boss("Boss", 1);
	std::cout << boss << std::endl;
	Bureaucrat righthand("rightHand", 2);
	std::cout << righthand << std::endl;
	Bureaucrat bureaucrat2("bureaucrat2", 149);
	std::cout << bureaucrat2 << std::endl;
	Form form1;
	std::cout << form1 << std::endl;
	Form bossform("Baws", 1, 1);
	std::cout << bossform << std::endl;

	/*Main bloc*/
	std::cout << YELLOW "Attempt to sign bossform by [" << boss.getName() << "]" RESET << std::endl;
	boss.signForm(bossform);
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to sign bossform by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.signForm(bossform);
	std::cout << std::endl;

	/*Same Test with upgraded righthand*/
	std::cout << YELLOW "Incrementing righthand level" <<  RESET << std::endl;
	righthand.incrementGrade();
	std::cout << righthand;
	std::cout << std::endl;
	std::cout << YELLOW "Attempt to sign bossform by [" << righthand.getName() << "]" RESET << std::endl;
	righthand.signForm(bossform);
	std::cout << std::endl;
	return (0);
}
