/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:28:11 by daumis            #+#    #+#             */
/*   Updated: 2024/02/28 02:50:36 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
private:
	typedef struct	s_FormList
	{
		const std::string&	formName;
		AForm*	(*func)(const std::string&);
	}	t_formList;
public:
	/*Methods*/
	AForm* makeForm(std::string formName, std::string target);
	/*Constructors / Destructors*/
	Intern();
	Intern(const Intern& ref);
	Intern&	operator=(const Intern& ref);
	~Intern();
	/*Exceptions Classes*/
	class InvalidFormName : public std::exception 
	{
		public:
			virtual const char * what(void) const throw();
	};
};

#endif