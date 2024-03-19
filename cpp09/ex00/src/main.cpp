/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/18 18:16:47 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << RED "Err: incorrect args\n Usage : ./btc <input_file>\n" RESET, 1);

	std::ifstream input_db(argv[1], std::ifstream::in);
	if (!input_db.is_open())
		return (std::cout << RED "Err: Could not open file: \'" << argv[1] << "\'\n" RESET, 1);

    std::ifstream internal_db("./data.csv", std::ifstream::in);
	if (!internal_db.is_open())
		return (std::cout << RED "Err: Could not open database file\n" RESET, 1);

	BitcoinExchange btc;
	btc.readCreateDataBase(internal_db);

	std::string line;
    std::getline(input_db, line);
	if (line != "date | value")
		return (std::cout << RED "Err: input file must start with: \'date | value\'\n" RESET, 1);

	std::cout << PURPLE "\n  [Date]     [Multiply]                                                  [Value]\n\n" RESET;
    while (std::getline(input_db, line))
    {
        size_t delim = line.find('|');
		if (delim == std::string::npos || line.length() < delim + 2)
		{
			std::cout << RED "Error: bad input => " << "\"" << line << "\"\n" RESET;
			continue ;
		}
		std::string date = line.substr(0, delim - 1);
		if (!btc.checkDateFormat(date) || !btc.checkDate(date))
			continue;

        std::string rate_as_str = line.substr(delim + 2);
		if (!btc.checkRateFormat(rate_as_str))
			continue;

		float rate = ft_stof(rate_as_str);
		std::cout	<< GREEN << date << RESET << " => " << rate;
		std::cout	<< " : " << std::fixed << std::setprecision(2);
		std::cout 	<< rate * btc.getRateFromDataBase(date) << std::endl;
    }
    input_db.close();
    internal_db.close();
	return (0);
}