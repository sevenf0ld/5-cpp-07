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
	FORMAT_COPY_CONTROL("DEFAULT CTOR");
	std::cout << "┕ size: " << arr_size_ << std::endl;
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
	FORMAT_COPY_CONTROL("PARAMETERIZED CTOR");
	std::cout << "┕ size: " << arr_size_ << std::endl;
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
	FORMAT_COPY_CONTROL("COPY CTOR");
}

// assignment operator overload
// deep copy
template <typename T>
//Array &Array<T>::operator=(const Array &rhs)
// error: invalid use of template-name ‘Array’ without an argument list
T &Array<T>::operator=(const Array &rhs)
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
	FORMAT_COPY_CONTROL("ASSIGNMENT OP");
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
	FORMAT_COPY_CONTROL("DTOR");
}

// LHS of an assignment must be a l-value (with a valid memory addr)
// the result of [] can be used on the LHS so the retval of the subscript operator must be an l-value
// references are always l-values because only variables with memory address allows references/aliases
// obj[i] evalues to obj.data_[i]
// returning by reference returns the actual obj.data_[i] array element
// if the subscript operator returns by value, it would return the value stored inside

// subscript operator overload
// throw an std::exception object if index is out of bounds
template <typename T>
T &Array<T>::operator[](size_t idx)
{
	return (const_cast<T&>(get_index(idx)));
}

template <typename T>
const T &Array<T>::operator[](size_t idx) const
{
	return (get_index(idx));
}

template <typename T>
const T &Array<T>::get_index(size_t idx) const
{
	//if (idx < 0 && idx >= arr_size_)
	// error: comparison of unsigned expression in ‘< 0’ is always false [-Werror=type-limits]
	if (idx >= arr_size_)
		throw std::exception();
		//throw std::out_of_range("index out of bounds");
	return (data_[idx]);
}

// returns the arr_size
// must not modify current instance
template <typename T>
size_t Array<T>::size(void) const
{
	return (arr_size_);
}
