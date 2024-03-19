/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:28 by daumis            #+#    #+#             */
/*   Updated: 2024/03/01 01:48:02 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

enum literal_type 
{
    error,
    type_char,
    type_int,
    type_float,
    type_double,
};

static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static double ft_stod(const std::string& str)
{
    double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static bool isChar(const std::string& literal)
{
    if (literal.length() != 1)
        return false;
    if (literal.at(0) < std::numeric_limits<char>::min()
     || literal.at(0) > std::numeric_limits<char>::max()
     || isdigit(literal.at(0)))
            return false;
    return true;
}

static bool isPseudoLiteral(const std::string& literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
          || literal == "-inf" || literal == "+inf"  || literal == "nan");
}

static bool isInt(const std::string& literal) 
{
    size_t startIndex = 0;

    if (literal.at(0) == '-')
        startIndex = 1;
    for (size_t i = startIndex; i < literal.length(); i++)
    {
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& literal)
{
    char lastChar = literal.at(literal.length() - 1);
    bool floating_point = false;
    size_t startIndex = 0;

    if (literal.at(0) == '-') 
        startIndex = 1;
    if (literal == "-inff" || literal == "+inff" ||  literal == "nanf")
        return (true);
    if (lastChar == 'f' || lastChar == 'F')
    {
        for (size_t i = startIndex; i < literal.length() - 1; i++)
        {
            if (literal.at(i) == '.')
            {
                if (floating_point)
                    return (false);
                floating_point = true;
            }
            else if (!isdigit(literal.at(i)))
                return (false);
        }
        return (true);
    }
    else
    {
        for (size_t i = startIndex; i < literal.length(); i++)
        {
            if (literal.at(i) == '.')
            {
                if (floating_point)
                    return (false);
                floating_point = true;
            }
            else if (!isdigit(literal.at(i)))
                return (false);
        }
        return (floating_point);
    }
}

static bool isDouble(const std::string& literal)
{
    bool    floating_point;

    if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "nanf")
        return true;
    floating_point = false;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (literal.at(i) == '.' && floating_point)
            return (false);
        else if (literal.at(i) == '.')
        {
            floating_point = true;
            continue ;
        }
        if (!isdigit(literal.at(i)))
            return (false);
    }
    return (true);
}

static literal_type getType(const std::string& literal)
{
    if (isChar(literal))
        return (type_char);
    if (isInt(literal))
        return (type_int);
    if (isFloat(literal))
       return (type_float);
    if (isDouble(literal))
       return (type_double);
    return error;
}

static void charCase(char ch)
{
    std::cout << "char: '" << ch << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

static void intCase(int nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
        std::cout << RED "char: Can't display" RESET << std::endl; 
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void floatCase(float nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << RED "char: Can't display" RESET << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << nbr << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void doubleCase(double nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
    else
        std::cout << RED "char: Can't display" RED << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << nbr << ".0" << std::endl;
}

static void pseudoLiteralCase(literal_type dest_type, const std::string& pseudo_literal)
{
    std::cout << RED "char: impossible type" RESET << std::endl;
    std::cout << RED "int: impossible type" RESET << std::endl; 
    if (dest_type == type_float)
    {
        std::cout << "float: " << pseudo_literal << std::endl;
        std::cout << "double: " << pseudo_literal.substr(0, pseudo_literal.length() - 1) << std::endl;
    }
    else if (dest_type == type_double)
    {
        std::cout << "float: " << pseudo_literal + "f" << std::endl;
        std::cout << "double: " << pseudo_literal << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    switch (getType(literal))
    {
        case type_char:
            charCase(literal.at(0));
            break;

        case type_int:
            intCase(ft_stoi(literal));
            break;

        case type_float:
            if (isPseudoLiteral(literal))
                pseudoLiteralCase(type_float, literal);
            else
                floatCase(ft_stof(literal));
            break;

        case type_double:
            if (isPseudoLiteral(literal))
                pseudoLiteralCase(type_double, literal);
            else
                doubleCase(ft_stod(literal));
            break;

        default:
            std::cout << "Type is unknown" << std::endl;
            break;
    }
}
