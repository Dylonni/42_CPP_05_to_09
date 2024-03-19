/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:10:29 by daumis            #+#    #+#             */
/*   Updated: 2024/03/07 22:28:55 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Array.hpp"
#include "./Array.tpp"

int main(void)
{
    Array<int> intArray(10);
    Array<int> intArray2( 10 - 5 );

    for (size_t i = 0; i < intArray.size(); i++)
        	intArray[i] = i * 2;

	for (size_t j = 0; j < intArray2.size(); j++)
        	intArray2[j] = j * 3;

	std::cout << "Int Array 1: " << intArray << std::endl;
	std::cout << "Int Array 2: " << intArray2 << std::endl;
	try 
	{
        std::cout	<< YELLOW "Accessing an invalid index (Array2[5]) : " RESET 
					<< intArray2[5] << std::endl;
    } 
	catch ( Array< int >::OutOfBoundsException& e ) 
	{
        std::cout << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }

	/*Assignation Copy*/
    intArray2 = intArray;
    std::cout << "Int Array 2: " << intArray2 << std::endl;

    try 
	{
        std::cout << YELLOW "Accessing a valid index Array1[5], value : " RESET << intArray[5] << std::endl;
        std::cout << YELLOW "Accessing a valid index Array2[6], value : " RESET << intArray2[6] << std::endl;
		std::cout << YELLOW "Accessing an invalid index Array2[10]: " RESET << intArray2[10] << std::endl;
    } 
	catch ( Array< int >::OutOfBoundsException& e ) 
	{
        std::cout << RED "EXECPTION: " << e.what() << RESET << std::endl;
    }

	Array<std::string>	string_arr(3);
	string_arr[0] = "Hello";
	string_arr[1] = "World";
	string_arr[2] = "!!";
	std::cout << "Original String Array  : " << PURPLE << string_arr << RESET << std::endl;
	
	Array<std::string>	stringsToCopy(2);
	stringsToCopy[0] = "My name is";
	stringsToCopy[1] = "Jeff";
	std::cout << "Strings to Copy        : " << PURPLE << stringsToCopy << RESET << std::endl;

	/*Assignation Copy*/
	string_arr = stringsToCopy;
	std::cout << "Original Array After Strings Copied : " << PURPLE << string_arr << RESET << std::endl;
	try
	{
		string_arr[3] = "Extra.";
		std::cout << RED "If everything is OK, we shouldn't cross this message" RESET << std::endl;
	}
	catch(Array<std::string>::OutOfBoundsException& e )
	{
	 	std::cout << RED "EXECPTION: " << e.what() << RESET << std::endl;
	}

    return (0);
}
