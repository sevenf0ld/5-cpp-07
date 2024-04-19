# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 14:54:50 by maiman-m          #+#    #+#              #
#    Updated: 2024/04/19 16:00:13 by maiman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "Array.hpp"

// try-catch is better suited in the event of a dynamic allocation failure so as to avoid the program from proceeding after printing an error message

// default ctor
// create an empty array
template <typename T>
Array<T>::Array()
{
	arr_size_ = 0;
	try
	{
		data_ = new T[arr_size_];
	}
	catch (std::bad_alloc &e)
	{
		NEW_ERR(e.what(), "default ctor");
		//NEW_ERR(std::string(e.what()), "default ctor");
	}
}

// parameterized ctor
// create an array of n size
template <typename T>
Array<T>::Array(unsigned int n)
{
	arr_size_ = static_cast<size_t>(n);
	try
	{
		data_ = new T[n];
	}
	catch (std::bad_alloc &e)
	{
		NEW_ERR(e.what(), "parameterized ctor");
		//NEW_ERR(std::string(e.what()), "parameterized ctor");
	}
}

// copy ctor
// deep copy
template <typename T>
Array<T>::Array(const Array &rhs)
{
	arr_size_ = rhs.arr_size_;
	//data_ = new T(*(rhs.data_)); // not another data type
	try
	{
		data_ = new T[arr_size_];
	}
	catch (std::bad_alloc &e)
	{
		NEW_ERR(e.what(), "copy ctor");
		//NEW_ERR(std::string(e.what()), "copy ctor");
	}
	for (size_t i = 0; i < arr_size_; i++)
		data_[i] = rhs.data_[i];
}

// assignment operator overload
// deep copy
template <typename T>
Array &Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		arr_size_ = rhs.arr_size_;
		if (data_ != NULL)
		{
			delete data_;
			data_ = NULL;
		}
		try
		{
			data_ = new T[arr_size_];
			for (size_t i = 0; i < arr_size_; i++)
				data_[i] = rhs.data_[i];
		}
		catch (std::bad_alloc &e)
		{
			NEW_ERR(e.what(), "assignment op");
			//NEW_ERR(std::string(e.what()), "assignment op");
		}
	}
	return (*this);
}

// dtor
template <typename T>
Array<T>::~Array()
{
	if (data_ != NULL)
	{
		delete[] data_;
		data_ = NULL;
	}
}

// subscript operator overload
// throw an std::exception object if index is out of bounds
template <typename T>
T &Array<T>::operator[](size_t idx)
{
	if (idx < 0 && idx >= arr_size_)
		throw std::exception();
	else
		return (data_[idx]);

}

// returns the arr_size
// must not modify current instance
template <typename T>
size_t Array<T>::size(void) const
{
	return (arr_size_);
}
