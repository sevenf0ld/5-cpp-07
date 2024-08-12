/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_two.hh                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:01:53 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/20 15:18:56 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZERO_TWO_HH
#define ZERO_TWO_HH

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

#define NEW_ERR(excpt_msg, err_msg) std::cerr << AC_RED << excpt_msg << '\t' << "Failed to instantiate in " << err_msg << "." << AC_NORMAL << std::endl
#define FORMAT_COPY_CONTROL(str) std::cout << AC_ITALIC << str << AC_NORMAL << std::endl
#define FORMAT_TEST(str) std::cout << AC_BOLD << AC_ITALIC << "[ " << str << " ]" << AC_NORMAL << std::endl
#define ACCESS_ERR(excpt_msg) std::cerr << AC_RED << excpt_msg << AC_NORMAL << std::endl

#define ARR_SIZE 5

// #include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

#include "Array.hpp"

/*
template <typename T>
void print_element(const Array<T> &arr_n)
{
	std::cout << arr_n;
}

template <typename T>
void iter(const Array<T> *arr, size_t arr_len, void (*f)(const Array<T> &))
{
	for (size_t i = 0; i < arr_len; i++)
		f(arr[i]);
}
*/

#endif
