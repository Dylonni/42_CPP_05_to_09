/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:05 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 01:07:34 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	ShrubberyCreationForm();
	static const int _reqExec = 145;
	static const int _reqSign = 137;
	static const std::string _shrubbery;
public:
	/*Methods*/
	const std::string&	getTarget() const;
	void				beExecuted() const;
	/*Constructors / Destructors*/
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();
};

#endif
