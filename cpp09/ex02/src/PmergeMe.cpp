/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:22:03 by daumis            #+#    #+#             */
/*   Updated: 2024/03/15 18:37:25 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe& ref)
{
    *this = ref;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
{
	(void)ref;
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

/*Quick conversion using stringstream to get u_int*/
unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

/*Print the vector*/
static void printVec(std::vector<unsigned int>& vec, int c)
{
	std::vector<unsigned int>::const_iterator itr;
	if (c == 1)
	{
		for (itr = vec.begin(); itr != vec.end(); itr++)
			std::cout << GREEN << *itr << " " << RESET;
	}
	else
	{
		for (itr = vec.begin(); itr != vec.end(); itr++)
			std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

/*Print the list*/
static void printList(std::list<unsigned int>& lst, int c)
{
	std::list<unsigned int>::const_iterator itr;
	if (c == 1)
	{
		for (itr = lst.begin(); itr != lst.end(); itr++)
			std::cout << GREEN << *itr << " " << RESET;
	}
	else
	{
		for (itr = lst.begin(); itr != lst.end(); itr++)
			std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
    std::vector<unsigned int> result;

    // Merge the two vectors until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    // Add any remaining elements from the left vector
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right vector
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return (result);
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec)
{
    if (vec.size() <= 1)
        return vec;

    // Divide the vector into two halves
    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    // Recursively sort the left and right halves
    left = mergeInsertVec(left);
    right = mergeInsertVec(right);

    // Merge the sorted halves
    return mergeVecs(left, right);
}

static std::list<unsigned int> mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right)
{
    std::list<unsigned int> result;

    // Merge the two vectors until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    // Add any remaining elements from the left vector
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right vector
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int>& lst)
{
    if (lst.size() <= 1)
        return lst;

    // Divide the list into two halves
    int mid = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

    for (int i = 0; i < mid; i++)
	{
        left.push_back(lst.front());
        lst.pop_front();
    }
    right = lst;

    // Recursively sort the left and right halves
    left = mergeInsertList(left);
    right = mergeInsertList(right);

    // Merge the sorted halves
    return mergeLists(left, right);
}

void PmergeMe::sortVec(int argc, char **argv)
{
	std::vector<unsigned int> storage;
	std::clock_t start = std::clock();

	for (int i = 1; i < argc; i += 1) 
		storage.push_back(ft_stou(argv[i]));

	std::cout << YELLOW "\n                                      [VECTOR] " RESET;
	std::cout << YELLOW "\nVector Before sort: " RESET;
	printVec(storage, 0);

	storage = mergeInsertVec(storage);
	this->_sortedTimeV = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << YELLOW "Vector After sort: " RESET;
	printVec(storage, 1);
}

void PmergeMe::sortList(int argc, char **argv)
{
	std::list<unsigned int> storage;

	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

	std::cout << PURPLE "                                       [LIST] " RESET;
    std::cout << PURPLE "\nList Before sort: " RESET;
	printList(storage, 0);

	std::clock_t start = std::clock();
	storage = mergeInsertList(storage);

	this->_sortedTimeL = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;
    std::cout << PURPLE "List After sort: " RESET;
	printList(storage, 1);
}

double PmergeMe::getTimeToSortL()
{
	return (this->_sortedTimeL);
}

double PmergeMe::getTimeToSortV()
{
	return (this->_sortedTimeV);
}

const char*	PmergeMe::InvalidElementException::what() const throw()
{
	return (RED "EXCEPTION: Wrong input" RESET);
}

const char*	PmergeMe::DuplicateException::what() const throw()
{
	return (RED "EXCEPTION: Duplicate value" RESET);
}
