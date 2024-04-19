/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:28:31 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 11:30:10 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
#define EQUAL_TEST 0

#include <iostream>

// function templates can be called with any argument type
// both arguments must have the same type
// both arguments must support all relational operators
// templates must be defined in the header file

// swap
// swap the two arguments, returns void
template <typename T>
void swap(T &a, T &b) // fn template definition for swap<T>
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

// min
// returns the smaller of the two arguments, returns the second if equal
template <typename T>
T min(const T &a, const T &b) // fn template definition for min<T>
{
	if (EQUAL_TEST)
		std::cout << AC_YELLOW << "(" << (a < b ? &a : &b) << ") " << AC_NORMAL << '\t';
	return (a < b ? a : b);
}

// max
// returns the greater of the two arguments, returns the second if equal
template <typename T>
T max(const T &a, const T &b) // fn template definition for max<T>
{
	if (EQUAL_TEST)
		std::cout << AC_YELLOW << "(" << (a < b ? &a : &b) << ") " << AC_NORMAL << '\t';
	return (a > b ? a : b);
}

#endif
