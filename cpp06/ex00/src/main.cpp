/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/01 01:37:58 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2 || !argv[1][0])
    {
        std::cerr << RED "Usage: ./convert " << YELLOW "<literal to convert>" RESET << "\n";
        return (1);
    }
    ScalarConverter::convert(argv[1]);
	return (0);
}
