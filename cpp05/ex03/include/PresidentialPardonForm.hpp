/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:40 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 03:01:46 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
	PresidentialPardonForm();
	static const int _reqExec = 25;
	static const int _reqSign = 5;
public:
	/*Methods*/
	const std::string&	getTarget() const;
	void				beExecuted() const;
	/*Constructors / Destructors*/
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();
};

#endif