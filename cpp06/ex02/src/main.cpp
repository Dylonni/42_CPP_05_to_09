/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/01 05:37:23 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base*	generate(void)
{
	int	rnb = std::rand() % 3;

	switch (rnb)
	{
		case 0:
			std::cout << "Generated: " GREEN "A" RESET;
			return (new A);
		case 1:
			std::cout << "Generated: " YELLOW "B" RESET;
			return (new B);
		case 2:
			std::cout << "Generated: " PURPLE "C" RESET;
			return (new C);
	}
	return (NULL);
}

void	identify(Base* p)
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << GREEN "A" RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW "B" RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << PURPLE "C" RESET;
	else
		std::cout << RED "Couldn't cast pointer" RESET;
}

void	identify(Base& p)
{
	std::cout << "Identified as reference: ";
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << GREEN "A" RESET;
	}
	catch (std::exception& e) { }
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << YELLOW "B" RESET;
	}
	catch (std::exception& e) { }
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << PURPLE "C" RESET;
	}
	catch (std::exception& e) { }
}

int	main(void)
{
	Base*	p;
	std::srand(std::time(NULL));

	for (int i = 1; i <= 15; i++)
	{
		std::cout << "Test [" << i << "]: ";
		p = generate();
		std::cout << ", ";
		identify(p);
		std::cout << ", ";
		identify(*p);
		delete (p);
		std::cout << std::endl;
	}
	return (0);
}