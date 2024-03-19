/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:49 by daumis            #+#    #+#             */
/*   Updated: 2024/03/15 18:35:45 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"
# define MICROSECOND 100000

#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <list>

class PmergeMe {
private:
	double	_sortedTimeV;
	double	_sortedTimeL;
public:
	/*Methods*/
	void sortVec(int argc, char **argv);
	void sortList(int argc, char **argv);
	double	getTimeToSortL();
	double	getTimeToSortV();
	/*Constructors / Destructor*/
	PmergeMe(void);
	PmergeMe(const PmergeMe& ref);
	PmergeMe &operator=(const PmergeMe& ref);
	~PmergeMe(void);
	/*Exceptions Classes*/
	class InvalidElementException : public std::exception
	{
		public:
			virtual const char* what() const throw();  
	};
	class DuplicateException : public std::exception
	{
		public:
			virtual const char* what() const throw();  
	};
};

unsigned int ft_stou(const std::string& str);

#endif