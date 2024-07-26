/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:05:37 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/27 00:55:46 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:
	Complex();
	Complex(const double n);
	Complex(const char a);
	Complex(const Complex &rhs);
	Complex &operator=(const Complex &rhs);
	~Complex();

	bool operator>(const Complex &rhs) const;
	bool operator<(const Complex &rhs) const;

	double get_double(void) const;
	char get_char(void) const;

private:
	double n_;
	char a_;
};

#endif
