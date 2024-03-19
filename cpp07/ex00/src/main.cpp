/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/05 00:15:24 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"

int main( void ) 
{
    int a = 2;
    int b = 3;
    std::cout << YELLOW "Before Swap" RESET<< std::endl;
    std::cout << CYAN "a = " << a << ", b = " << b << RESET << std::endl;
    ::swap( a, b );
    std::cout << YELLOW "After Swap" RESET << std::endl;
    std::cout << CYAN "a = " << a << ", b = " << b << RESET << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << YELLOW "Before Swap" RESET<< std::endl;
    std::cout << CYAN "c = " << c << ", d = " << d << RESET << std::endl;
    ::swap(c, d);
    std::cout << YELLOW "After Swap" RESET << std::endl;
    std::cout << CYAN "c = " << c << ", d = " << d << RESET << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}