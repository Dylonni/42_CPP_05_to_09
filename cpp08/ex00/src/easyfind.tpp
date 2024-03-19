/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:48 by daumis            #+#    #+#             */
/*   Updated: 2024/03/05 22:47:51 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::const_iterator easyfind(const T& container, const int toFind)
{
    typename T::const_iterator    iter;

    iter = std::find(container.begin(), container.end(), toFind);
	if (iter != container.end())
	    return (iter);
    else
	    throw NoMatchException();
}

const char* NoMatchException::what() const throw()
{
    return ("Value has not been found in the container\n");
}

#endif
