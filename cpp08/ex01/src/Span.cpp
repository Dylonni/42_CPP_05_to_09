/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:37:11 by daumis            #+#    #+#             */
/*   Updated: 2024/03/12 18:09:00 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span(): _numbers(), _maxSize(0){}

Span::Span(const Span& ref): _numbers(ref._numbers), _maxSize(ref._maxSize){}

Span::Span(unsigned int N): _numbers(), _maxSize(N){}

Span& Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		this->_maxSize = ref._maxSize;
		this->_numbers.clear();
		this->_numbers.insert(this->_numbers.end(), ref._numbers.begin(), ref._numbers.end());
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->_numbers.size() >= this->_maxSize) 
		throw MaxSizeExceeded();
	this->_numbers.push_back(num);
}


unsigned int Span::shortestSpan() const
{
	int shortest;
	std::vector<int> sortedNumbers;

	if (this->_numbers.size() <= 1) 
		throw SpanTooShort();
	sortedNumbers = this->_numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); ++i) 
        shortest = std::min(shortest, sortedNumbers[i] - sortedNumbers[i - 1]);
    return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (this->_numbers.size() <= 1) 
		throw SpanTooShort();
	return (*std::max_element(this->_numbers.begin(), this->_numbers.end()) -
			*std::min_element(this->_numbers.begin(), this->_numbers.end()));
}

const std::vector<int>&	Span::getNumbers(void) const
{
	return (this->_numbers);
}

const char* Span::SpanTooShort::what() const throw()
{
    return ("Can't calculate any length, there should be at least 2 values in the span\n");
}

const char* Span::MaxSizeExceeded::what() const throw()
{
    return ("Size of the span is not enough to add more values\n");
}

Span::~Span(){}
