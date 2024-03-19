/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/12 19:36:39 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

int main(void) 
{
    std::srand(time(NULL));
    std::string                         input;
    std::vector<int>                    vec;
    std::vector<int>::const_iterator    result;
    int	                                value_to_find = 0;
    
    for (size_t i = 0; i < 10; i++)
        vec.push_back(rand() % 100);
    system("clear");
    std::cout << "               Values in vector" << std::endl; 
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end() ; it++)
        std::cout << "[" << *it << "] ";

    std::cout << std::endl;

    std::cout << PURPLE "      Enter the value you are searching for" << RESET << std::endl;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    if (!(ss >> value_to_find))
		return (std::cout << RED "Invalid input" << RESET << std::endl, 1);
    try 
    {
        result = easyfind(vec, value_to_find);
        system("clear");
        std::cout   << GREEN "           Value " RESET << value_to_find << RESET
                    << GREEN " Has been found !" RESET << std::endl;
        for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end() ; it++)
        {
            if (result == it)
                std::cout << YELLOW "[" << *it << "] " RESET;
            else
                std::cout << "[" << *it << "] ";
        }
        std::cout << std::endl;
    }
    catch(NoMatchException& e)
    {
        std::cerr << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }
    return (0);
}
