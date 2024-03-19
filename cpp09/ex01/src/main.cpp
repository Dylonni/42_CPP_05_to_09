/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/19 21:11:23 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
        return (std::cout << RED "Err: wrong arguments. Usage: ./RPN <operands/operators>\n" RESET, 1);

	if (!RPN::checkExpression(argv[1]))
        return (std::cout << RED "Err: Expression cannot be calculated\n" RESET, 1);

    try
	{
        std::cout << YELLOW << RPN::calculate(argv[1]) << RESET << std::endl;
    }
    catch (std::exception& e)
	{
       std::cout << e.what() << "\n";
    }
	return (0);
}
