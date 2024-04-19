/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:42:10 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 14:53:50 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &rhs);
	Array &operator=(const Array &rhs);
	~Array();

	T &operator[](size_t idx);
	size_t size(void);

private:
	size_t arr_size_;
	T *data_;
};

#include "Array.tpp"

#endif
