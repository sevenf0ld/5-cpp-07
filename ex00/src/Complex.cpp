/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:14:54 by maiman-m          #+#    #+#             */
/*   Updated: 2024/07/27 00:51:22 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

Complex::Complex()
	   : n_(9.0), a_('a')
{
}

Complex::Complex(const double n)
	   : n_(n), a_('a')
{
}

Complex::Complex(const char a)
	   : n_(9.0), a_(a)
{
}

Complex::Complex(const Complex &rhs)
	   : n_(rhs.n_), a_(rhs.a_)
{
}

Complex &Complex::operator=(const Complex &rhs)
{
	if (this != &rhs)
	{
		n_ = rhs.n_;
		a_ = rhs.a_;
	}
	return (*this);
}

Complex::~Complex()
{
}

bool Complex::operator>(const Complex &rhs) const
{
	return (n_ > rhs.n_ && a_ > rhs.a_);
}

bool Complex::operator<(const Complex &rhs) const
{
	return (n_ < rhs.n_ && a_ < rhs.a_);
}

double Complex::get_double(void) const
{
	return (n_);
}

char Complex::get_char(void) const
{
	return (a_);
}
