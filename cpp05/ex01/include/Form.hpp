/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:51 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 15:53:07 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_reqSign;
	const int			_reqExec;
	bool				_isSigned;
public:
	/*Methods*/
	const std::string&	getName() const;
	int					getReqSign() const;
	int					getReqExec() const;
	bool				getStatus() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	/*Constructors / Destructors*/
	Form();
	Form(const std::string& name, const int reqSign, const int reqExec);
	Form(const Form& ref);
	Form& operator=(const Form& ref);
	~Form();
	/*Exceptions Classes*/
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, Form const& rhs);

#endif
