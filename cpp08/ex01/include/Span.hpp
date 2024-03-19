/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:51 by daumis            #+#    #+#             */
/*   Updated: 2024/03/12 18:09:43 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"

#include <iostream>
#include <istream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>


class Span
{
private:
	std::vector<int>	_numbers;
	size_t				_maxSize;
public:
	/*Methods*/
	void					addNumber(int num);
	unsigned int			shortestSpan() const;
	unsigned int			longestSpan() const;
	const std::vector<int>&	getNumbers(void) const;
	template<typename C>
	void addNumbers(C begin, C end)
	{
		size_t rangeSize;

		rangeSize = std::distance(begin, end);
		if (this->_numbers.size() + rangeSize > this->_maxSize)
			throw MaxSizeExceeded();
		this->_numbers.insert(this->_numbers.end(), begin, end);
	}
	/*Constructors / Destructors*/
	Span();
	Span(const Span& ref);
	Span(unsigned int N);
	Span& operator=(const Span& ref);
	~Span();
	/*Exceptions Classes*/
	class SpanTooShort: public std::exception 
	{
		public:
			virtual const char * what(void) const throw();
	};
	class MaxSizeExceeded: public std::exception 
	{
		public:
			virtual const char * what(void) const throw();
	};
};

#endif
