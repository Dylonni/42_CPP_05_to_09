/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:07:48 by daumis            #+#    #+#             */
/*   Updated: 2024/03/11 17:01:23 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(): _array(new T()), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array& ref): _array(new T[ref._size]), _size(ref._size)
{
	for (size_t i = 0; i < this->_size; i++)
		this->_array[i] = ref._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
    if (this != &ref)
    {
        if (this->_size != ref._size)
        {
            delete [] this->_array;
            this->_array = new T[ref._size];
            this->_size = ref._size;
        }
        for (size_t i = 0; i < ref._size; i++)
            this->_array[i] = ref._array[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index) 
{
        if (index >= _size)
            throw OutOfBoundsException();
        return (this->_array[index]);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
size_t Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return ("You are out of bounds\n");
}

template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &rhs)
{
    for (unsigned int i = 0; i < rhs.size(); ++i)
        os << "[" << rhs[i] << "] ";
    return (os);
}

#endif
