/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:51 by daumis            #+#    #+#             */
/*   Updated: 2024/02/27 22:51:31 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	virtual void	beExecuted(void) const = 0;
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
	void				execute(const Bureaucrat& executor) const;
	/*Constructors / Destructors*/
	AForm();
	AForm(const std::string& name, const int reqSign, const int reqExec);
	AForm(const AForm& ref);
	AForm& operator=(const AForm& ref);
	virtual ~AForm();
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
	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, AForm const& rhs);

#endif
