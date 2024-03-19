/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:49 by daumis            #+#    #+#             */
/*   Updated: 2024/03/05 23:53:15 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
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

template <typename T>
typename T::const_iterator easyfind(const T& container, const int toFind);

class NoMatchException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#include "../src/easyfind.tpp"

#endif