/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/05 02:38:35 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Printing intArray: ";
    ::iter(intArray, 5, ::printElement<int>);
    std::cout << std::endl;

    std::cout << "Printing doubleArray: ";
    ::iter(doubleArray, 5, ::printElement<double>);
    std::cout <<std::endl;

    std::cout << "Printing charArray: ";
    ::iter(charArray, 5, ::printElement<char>);
    std::cout << std::endl;

    return (0);
}
