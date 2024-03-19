/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:22:03 by daumis            #+#    #+#             */
/*   Updated: 2024/03/18 18:04:19 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/*Simple conversion from string to unsigned int usign sstream*/
unsigned int ft_stou(const std::string& str)
{
    unsigned int num;
    std::stringstream ss(str);

    ss >> num;
    return (num);
}

/*Simple conversion from string to float usign sstream*/
float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return (num);
}

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
    *this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	if (this != &ref)
    	this->_dataBase = ref._dataBase;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void){};

/*Returns the value of the bitcoin at the precise date, or returns the closest previous value*/
float BitcoinExchange::getRateFromDataBase(const std::string& date)
{
	std::map<std::string, float>::iterator it = this->_dataBase.lower_bound(date);

    if (this->_dataBase.count(date) > 0)
    	return (std::cout << RESET "                                         final value = " CYAN, this->_dataBase.at(date));
	else
		--it;
    return (std::cout << RESET "(Closest previous date is \'" YELLOW << it->first << RESET "\'),  final value = " CYAN,(it->second));
}

/*Checks if the Date format is correct to be found in the input file*/
bool BitcoinExchange::checkDateFormat(const std::string &date)
{
	if (date.empty())
		return (false);

 	size_t dash = date.find('-');
    size_t scnd_dash = date.find('-', dash + 1);

	if (dash == std::string::npos || scnd_dash == std::string::npos
	||  date.find_first_not_of("0123456789.-") != std::string::npos)
	{
		std::cout << RED "Error: bad input => " << "\"" << date << "\"\n" RESET;
		return (false);
	}
	return (true);
}

/*Checks if the date is possible*/
bool BitcoinExchange::checkDate(const std::string& date)
{
	std::string s;
	int year, month, day;
	std::istringstream ss(date);
	int i = 0;

	while (std::getline(ss, s, '-'))
	{
		if (i == 0)
		{
			year = ft_stou(s);
			if (year < 2009 || year > 2022)
			{
				std::cout << RED "Error: year is not defined in the database => " << "\"" << date << "\"\n" RESET;
				return (false);
			}
		}
		if (i == 1)
		{
			month = ft_stou(s);
			if (month < 1 || month > 12)
			{
				std::cout <<  RED "Error: incorrect month => " << "\"" << date << "\"\n" RESET;
				return (false);
			}
		}
		if (i == 2)
		{
			day = ft_stou(s);
			if ((day < 1 || day > 31)
			||  (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
			||  (day > 28 && month == 2))
			{
				std::cout << RED "Error: incorrect day => "<< "\"" << date << "\"\n" RESET;
				return (false);
			}
		}
		i++;
	}
	if (i != 3)
	{
		std::cout << RED "Error: incorrect date => " << "\"" << date << "\"\n";
		return (false);
	}
	return (true);
}

bool BitcoinExchange::checkRateFormat(const std::string& rate)
{
	if (rate.empty() || rate.find_first_not_of("0123456789.-") != std::string::npos
	||  rate.at(0) == '.' || rate.find('.', rate.length() - 1) != std::string::npos)
		std::cout << RED "Error: invalid rate => " << "\"" << rate << "\"\n" RESET;
	else if (rate.at(0) == '-')
		std::cout << RED "Error: not a positive number.\n" RESET;
	else if (rate.length() > 10 || (rate.length() == 10 && rate > "2147483647"))
		std::cout << RED "Error: too large a number.\n" RESET;
	else
		return (true);
	return (false);
}

/*Read from data.csv and create the database in the Object*/
void BitcoinExchange::readCreateDataBase(std::ifstream& internal_db)
{
    std::string line;
    size_t delim;

    std::getline(internal_db, line);
    while (std::getline(internal_db, line))
    {
        delim = line.find(',');
        std::string rate = line.substr(delim + 1);
        this->_dataBase[line.substr(0, delim)] = ft_stof(rate);
    }
    internal_db.close();
}
