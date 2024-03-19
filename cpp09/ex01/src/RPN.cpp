/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:22:03 by daumis            #+#    #+#             */
/*   Updated: 2024/03/19 21:16:35 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

/*Simple conversion from string to int using sstream*/
static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

RPN::RPN(void){}

RPN::RPN(const RPN& ref)
{
    *this = ref;
}

RPN& RPN::operator=(const RPN& ref)
{
	(void)ref;
    return (*this);
}

RPN::~RPN(void){};

/*Checks if the expression is correct*/
bool RPN::checkExpression(const std::string& expr)
{
    std::stringstream   postfix(expr);
    std::stack<int>     to_check;
    std::string         s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
            continue;
		to_check.push(ft_stoi(s));
	}
    if (to_check.empty())
        return (false);
    while (!to_check.empty())
    {
        if (to_check.top() > 9)
            return (false);
        to_check.pop();
    }
	if (expr.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return (true);
	return (false);
}

/*Algorithm used to calculate the given expression*/
long long RPN::calculate(const std::string& expr)
{
	int					left;
	int					right;
    int					result;
    std::stringstream	postfix(expr);
    std::stack<int>		temp;
    std::string			s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (temp.size() < 2)
                throw NoResultException();
			right = temp.top();
			temp.pop();
			left = temp.top();
			temp.pop();
            switch (s.at(0))
            {
                case '+':
					result =  left + right; 
					break;
                case '-':
					result =  left - right;
					break;
                case '/':
                    if (right != 0)
					{
                        result =  left / right; 
					}
                    else
					{
                        throw DivisionByZeroException();
					}
               		break;
                case '*': 
					result =  left * right;
					break;
            }
            temp.push(result);
        }
        else
            temp.push(ft_stoi(s));
    }
	return (temp.top());
}

const char*	RPN::NoResultException::what() const throw()
{
	return (RED "EXCEPTION: Can't calculate expression with only 1 member" RESET);
}

const char*	RPN::DivisionByZeroException::what() const throw()
{
	return (RED "EXCEPTION: Cannot divide by 0" RESET);
}
