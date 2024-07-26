/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:27:08 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/27 12:51:55 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Complex.hpp"

std::ostream &operator<<(std::ostream &out_stream, const Complex &obj)
{
	out_stream << AC_CYAN << "num: " << obj.get_double()
			   << ", alpha: " << obj.get_char() << AC_NORMAL << std::endl;
	return (out_stream);
}

/*
 * template params/args <>
 * function params/args ()
 *
 * invoking template ::swap<int>
 * compiler instantiates the template to create a function
 * the argument provided substitutes all template instances' parameter
 * invoking function returned by the template with function args ::swap<int>(4, 10)
 *
 * ::swap(4, 10) makes use of template argument deduction because the compiler can infer the template argument type to support the invocation
 * deduction is not possible if different types are provided as function args
 *
 * multi template types and default args can be achieved with templates
 */

// global scope is nameless. an empty LHS is a request to fetch the RHS name from the global scope

int main(void)
{
	if (EQUAL_TEST == 0)
	{
		FORMAT_TEST("SUBJECT PDF TEST");
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
		std::cout << std::endl;

		FORMAT_TEST("ANY/COMPLEX TYPE TEST");
		std::cout << std::endl;
		Complex small(1.0);
		Complex large('z');

		TEST("SMALL & LARGE BEFORE SWAP")
		std::cout << "small:" << std::endl << small;
		std::cout << "large:" << std::endl << large;
		std::cout << std::endl;

		::swap(small, large);
		
		TEST("SMALL & LARGE AFTER SWAP")
		std::cout << "small:" << std::endl << small;
		std::cout << "large:" << std::endl << large;
		std::cout << std::endl;

		TEST("SMALL vs LARGE MIN")
		std::cout << "min(small, large) = " << ::min(small, large) << std::endl;

		TEST("SMALL vs LARGE MAX")
		std::cout << "max(small, large) = " << ::max(small, large) << std::endl;
	}

	if (EQUAL_TEST)
	{
		FORMAT_TEST("RETURN SECOND IF EQUAL TEST");
		float x = 1.0f;
		float y = 1.0f;

		std::cout << "address of x: " << &x << std::endl
				  << "address of y: " << &y << std::endl
				  << "address of min(x, y) should be equal to that of y: " << ::min(x, y) << std::endl
				  << "address of max(y, x) should be equal to that of x: " << ::max(y, x) << std::endl;
		std::cout << std::endl;
	}
}
