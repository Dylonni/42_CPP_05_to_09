/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:22 by dylan             #+#    #+#             */
/*   Updated: 2024/02/28 01:30:44 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
	RobotomyRequestForm();
	static const int _reqExec = 72;
	static const int _reqSign = 45;
public:
	/*Methods*/
	const std::string&	getTarget() const;
	void				beExecuted() const;
	/*Constructors / Destructors*/
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();
};

#endif