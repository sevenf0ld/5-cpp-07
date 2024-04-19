/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:52:20 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 13:48:59 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

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

#define FORMAT_TEST(str) std::cout << AC_BOLD << AC_ITALIC << str << AC_NORMAL << std::endl;
#define arr_size(arr) sizeof(arr) / sizeof(arr[0])

#include <iostream>

// takes in 3 parameters and returns void
// ┕ arr_addr
// ┕ arr_len
// ┕ function to call on arr[n] (can be an instantiated fn_template)
// must work with any type of array

// template <typename T1, typename T2 = size_t> // hints that only the arr will be of varying type
// size_t is commonly used for array indexing and loop counting. Programs that use other types, such as unsigned int, for array indexing may fail on, e.g. 64-bit systems when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic.

template <typename T>
void multiply_by_two(const T &arr_n)
{
	std::cout << arr_n << " to " << AC_RED << arr_n * 2 << AC_NORMAL << std::endl;
}

template <typename T>
void decrement_by_one(const T &arr_n)
{
	std::cout << arr_n << " to " << AC_YELLOW << arr_n - 1 << AC_NORMAL << std::endl;
}

template <typename T>
void print_last_char(const T &arr_n)
{
	std::cout << AC_GREEN << arr_n.at(arr_n.length() - 1) << AC_NORMAL << " of " << arr_n << std::endl;
}

template <typename T>
void iter(const T *arr, size_t arr_len, void (*f)(const T &))
{
	for (size_t i = 0; i < arr_len; i++)
		f(arr[i]);
}

#endif
