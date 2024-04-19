/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:42:10 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 18:21:00 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"
#define AC_BOLD "\033[1m"
#define AC_ITALIC "\033[3m"

#define NEW_ERR(excpt_msg, err_msg ) std::cerr << AC_RED << excpt_msg << '\t' << "Failed to instantiate in " << err_msg << "." << AC_NORMAL << std::endl
#define FORMAT_COPY_CONTROL(str) std::cout << AC_GREEN << str << AC_NORMAL << std::endl
#define FORMAT_TEST(str) std::cout << AC_BOLD << AC_ITALIC << str << AC_NORMAL << std::endl

#include <exception>
//#include <stdexcept>
#include <string>
#include <iostream>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &rhs);
	//Array &operator=(const Array &rhs);
	T &operator=(const Array &rhs);
	~Array();

	T &operator[](size_t idx);
	const T &operator[](size_t idx) const;
	size_t size(void) const;

private:
	size_t arr_size_;
	T *data_;

	// remove redundancy in the subscript operator overload by refactoring the logic into a private const member function
	const T &get_index(size_t idx) const;
};

#include "Array.tpp"

#endif
