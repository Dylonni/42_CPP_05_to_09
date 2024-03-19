/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/18 18:20:43 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	    return ((std::cout << RED "No numbers to sort. Usage: ./PmergeMe <numbers to sort>\n" RESET), 1);
    if (argc == 2)
       return ((std::cout << RED "Can't sort only 1 argument, there must be at least 2\n" RESET), 1);
    PmergeMe pmm;

    try {
        for (int i = 1; i < argc; i += 1)
        {
            if (std::string(argv[i]).find_first_not_of("0123456789\'\0 ") != std::string::npos)
                throw PmergeMe::InvalidElementException();
            if (std::string(argv[i]).empty())
                throw PmergeMe::InvalidElementException();
        }

        std::vector<unsigned int>temp;
        for (int i = 1; i < argc; i += 1)
            temp.push_back(ft_stou(argv[i]));

        std::vector<unsigned int>::iterator itr;
        std::vector<unsigned int>::iterator itr2;
        for (itr = temp.begin(); itr != temp.end(); itr++)
        {
            for (itr2 = itr + 1; itr2 != temp.end(); itr2++)
                if (*itr2 == *itr)
			        throw PmergeMe::DuplicateException();
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return (1);
    }

    pmm.sortVec(argc, argv);
    pmm.sortList(argc, argv);
    std::cout << YELLOW "\nTime to process a range of " << argc - 1
		 << " elements " << "in a vector : " << pmm.getTimeToSortV() << " µs" RESET << std::endl;
    std::cout << PURPLE "Time to process a range of " << argc - 1
		 << " elements " << "in a list : " << pmm.getTimeToSortL() << " µs" RESET << std::endl;
	return (0);
}