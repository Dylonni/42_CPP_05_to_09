/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:51 by daumis            #+#    #+#             */
/*   Updated: 2024/03/11 23:19:36 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# define RESET	"\e[0m"
# define RED	"\e[1;31m"
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;93m"
# define BLUE	"\e[1;34m"
# define PURPLE	"\e[1;35m"
# define CYAN	"\e[1;36m"

#include <iostream>
#include <stack>
#include <algorithm> 

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
	typedef typename std::stack<T, C>::container_type::iterator	iterator;
	/*Methods*/
	iterator begin();
	iterator end();
	/*Constructors / Destructor*/
	MutantStack();
	MutantStack(const MutantStack<T, C>& ref);
	MutantStack& operator=(const MutantStack<T, C>& ref);
	~MutantStack();
};

#include "./MutantStack.tpp"

#endif
