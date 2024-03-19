/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:49 by daumis            #+#    #+#             */
/*   Updated: 2024/03/14 21:47:25 by daumis           ###   ########.fr       */
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
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> _dataBase;
public:
	/*Methods*/
	void	readCreateDataBase(std::ifstream& internal_db);
	bool	checkDateFormat(const std::string& date);
	bool	checkRateFormat(const std::string& rate);
	bool 	checkDate(const std::string& date);
	float	getRateFromDataBase(const std::string& date);
	/*Constructors / Destructor*/
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator=(const BitcoinExchange& ref);
	~BitcoinExchange();
};

float ft_stof(const std::string& str);
unsigned int ft_stou(const std::string& str);

#endif