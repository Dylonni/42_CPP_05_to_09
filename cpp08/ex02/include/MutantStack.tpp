/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:48 by daumis            #+#    #+#             */
/*   Updated: 2024/03/11 23:30:53 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

template <typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>(){}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C>& ref) : std::stack<T, C>(ref){}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::   operator=(const MutantStack<T, C>& ref)
{
	if (this != &ref)
		this->c = ref.c;
	return (*this);
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack(void) {};

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
    return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
    return (this->c.end());
}


#endif
