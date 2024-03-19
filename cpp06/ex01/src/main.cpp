/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:26 by daumis            #+#    #+#             */
/*   Updated: 2024/03/01 05:05:01 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main(void)
{
	/*Initialization*/
	Data data_set;
	Data* deserializedPtr;
	uintptr_t serializedToIntPtr;

	data_set.string = std::string("Hello");
	serializedToIntPtr = Serializer::serialize(&data_set);
	deserializedPtr = Serializer::deserialize(serializedToIntPtr);

	/*std::cout informations*/
	std::cout	<< "[Original \"data_set\" values]\n[String] : \"" PURPLE
				<< data_set.string << RESET << "\"\n[Adress] : " << PURPLE << &data_set
				<< RESET << std::endl << std::endl;
	std::cout	<< "Serialized &data_set [Adress to Int]: " CYAN
				<< serializedToIntPtr << RESET << std::endl;
	std::cout	<< "Deserialized data_set [Adress]      : " CYAN
				<< deserializedPtr << RESET << std::endl 
				<< "Deserialized data_set->string       : \"" CYAN
				<< deserializedPtr->string << RESET "\"\n" << std::endl;
	std::cout	<< YELLOW "                           " RESET <<
				PURPLE << "Original" << RESET << " | " CYAN 
				<< "Deserialized" << RESET << std::endl;
	std::cout	<< YELLOW "Comparing Adresses : " RESET <<
				PURPLE << &data_set << RESET << " | " CYAN 
				<< deserializedPtr << RESET << std::endl;
	std::cout	<< YELLOW "Comparing Strings  :        " RESET "\"" <<
				PURPLE << data_set.string << RESET << "\" | \"" CYAN 
				<< deserializedPtr->string << RESET << "\"\n" << std::endl;
	if (&data_set == deserializedPtr)
		std::cout	<< GREEN "Adresses are matching after deserialization ✅" RESET << std::endl;
	else 
		std::cout	<< RED "Adresses don't match, deserialization failed ❌" RESET << std::endl;
	return (0);
}
