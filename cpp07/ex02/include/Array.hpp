/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:51 by daumis            #+#    #+#             */
/*   Updated: 2024/03/05 05:24:34 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# define MAX_VAL 750
# define NB_VALUES 20
# define LESS_VALUES 5
# define MORE_VALUES 25

# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"

#include <iostream>
#include <cstdlib> 

template <typename T = int>
class Array
{
private:
	T*		_array;
	size_t	_size;

public:
	/*Methods*/
	size_t	size() const;
	T& operator[](size_t index);
	/*Constructors / Destructor*/
	Array();
	Array(unsigned int n);
	Array(const Array& ref);
	Array& operator=(const Array& ref);
	~Array();
	/*Exceptions Classes*/
	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

template <typename T>
std::ostream&	operator<<(std::ostream &os, Array<T> &rhs);

#include "../src/Array.tpp"

#endif