/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:42:10 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 16:16:43 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define NEW_ERR(excpt_msg, err_msg ) std::cerr << AC_RED << except_msg << '\t' << "Failed to instantiate in " << str << "." << AC_NORMAL << std::endl

#include <exception>
#include <string>

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
	const T &operator[](size_t idx) const;
	size_t size(void) const;

private:
	size_t arr_size_;
	T *data_;
};

#include "Array.tpp"

#endif
