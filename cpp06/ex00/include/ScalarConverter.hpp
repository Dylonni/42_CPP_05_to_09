/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:49 by daumis            #+#    #+#             */
/*   Updated: 2024/03/01 02:18:24 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

class ScalarConverter
{
private:
	/*Constructors / Destructors*/
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ref);
	ScalarConverter& operator=(const ScalarConverter& ref);
	~ScalarConverter();
public:
	/*Methods*/
	static void convert(const std::string& literal);
};

#endif