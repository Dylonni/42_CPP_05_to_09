/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:49 by daumis            #+#    #+#             */
/*   Updated: 2024/03/14 23:34:39 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"

#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stack>

class RPN
{
public:
	/*Methods*/
	static bool			checkExpression(const std::string& expr);
    static long long	calculate(const std::string& expr);
	/*Constructors / Destructor*/
	RPN();
	RPN(const RPN& ref);
	RPN& operator=(const RPN& ref);
	~RPN();
	/*Exceptions Classes*/
	class NoResultException : public std::exception 
	{
		public:
			virtual const char* what() const throw();  
    };

        class DivisionByZeroException : public std::exception
	{
		public:
			virtual const char* what() const throw();  
    };
};

#endif