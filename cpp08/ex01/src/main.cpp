/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/12 18:06:55 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
    unsigned int longest;
    unsigned int shortest;
    std::srand(time(NULL));
    Span    span(10000);

    for (size_t i = 0; i < 10000; i++)
        span.addNumber(rand());

    std::cout << "             Values in span" << std::endl; 
    for (std::vector<int>::const_iterator it = span.getNumbers().begin(); it != span.getNumbers().end(); it++)
        std::cout << "[" << *it << "] ";

    std::cout << std::endl;
    try 
    {
        longest = span.longestSpan();
        shortest = span.shortestSpan();
        std::cout   << GREEN "\nLongest span found : " << longest 
                    << RESET << std::endl;
        std::cout   << GREEN "Shortest span found : " << shortest 
                    << RESET << std::endl;
    }
    catch(Span::SpanTooShort& e)
    {
        std::cerr << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW "\nTrying to add more Values to the same span" << std::endl;
    try 
    {
        std::vector<int> toAdd;
        for (size_t i = 0; i < 10; i++)
            toAdd.push_back(rand());
        span.addNumbers(toAdd.begin(), toAdd.end());
        longest = span.longestSpan();
        shortest = span.shortestSpan();
        std::cout << GREEN "Longest span found : " << longest << RESET << std::endl;
        std::cout << GREEN "Shortest span found : " << shortest << RESET << std::endl;
    }
    catch(Span::MaxSizeExceeded& e)
    {
        std::cerr << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW "\nCreating another span capable of containing more Values" << std::endl;
    try
    {
        Span span2(100000);
        std::vector<int> toAdd;

        for (size_t i = 0; i < 10000; i++)
            span2.addNumber(rand());
        for (size_t i = 0; i < 10000; i++)
            toAdd.push_back(rand());
        span2.addNumbers(toAdd.begin(), toAdd.end());
        longest = span2.longestSpan();
        shortest = span2.shortestSpan();
        std::cout << GREEN "Longest span found : " << longest << RESET << std::endl;
        std::cout << GREEN "Shortest span found : " << shortest << RESET << std::endl;
    }
    catch(Span::MaxSizeExceeded& e)
    {
         std::cerr << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }
    std::cout << YELLOW "\nCreating a span that is too short" RESET << std::endl;
    try
    {
        Span span3(1);
 
        span3.addNumber(rand());
        std::cout << "Values in span" << std::endl; 
        for (std::vector<int>::const_iterator it = span3.getNumbers().begin(); it != span3.getNumbers().end(); it++)
            std::cout << "[" << *it << "] \n";
        longest = span3.longestSpan();
        shortest = span3.shortestSpan();
        std::cout << GREEN "Longest span found : " << longest << RESET << std::endl;
        std::cout << GREEN "Shortest span found : " << shortest << RESET << std::endl;
    }
    catch(Span::SpanTooShort& e)
    {
         std::cerr << RED "EXCEPTION: " << e.what() << RESET << std::endl;
    }
    return (0);
}

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return (0);
// }