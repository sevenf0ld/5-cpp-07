int flag = 0;

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
	}
	FORMAT_COPY_CONTROL("Default ctor called.");
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
		for (size_t i = 0; i < arr_size_; i++)
			data_[i] = 0;
	}
	catch (std::bad_alloc &e)
	{
		NEW_ERR(e.what(), "parameterized ctor");
	}
	FORMAT_COPY_CONTROL("Parameterized ctor called.");
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
		for (size_t i = 0; i < arr_size_; i++)
			data_[i] = rhs.data_[i];
	}
	catch (std::bad_alloc &e)
	{
		NEW_ERR(e.what(), "copy ctor");
	}
	FORMAT_COPY_CONTROL("Copy ctor called.");
}

// assignment operator overload
// deep copy
template <typename T>
Array <T>&Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		arr_size_ = rhs.arr_size_;
		if (data_ != NULL)
		{
			delete[] data_;
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
		}
	}
	FORMAT_COPY_CONTROL("Assignment op called.");
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
	FORMAT_COPY_CONTROL("Dtor called.");
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
	if (flag == 1)
		std::cout << " [ calling non-const version ] ";
	flag = 0;
	return (const_cast<T&>(get_index(idx)));
}

template <typename T>
const T &Array<T>::operator[](size_t idx) const
{
	if (flag == 1)
		std::cout << " [ calling const version ] ";
	flag = 0;
	return (get_index(idx));
}

template <typename T>
const T &Array<T>::get_index(size_t idx) const
{
	//if (idx < 0 && idx >= arr_size_)
	// error: comparison of unsigned expression in ‘< 0’ is always false [-Werror=type-limits]
	if (idx >= arr_size_)
		//throw std::exception();
		throw std::out_of_range("index out of bounds");
	return (data_[idx]);
}

// returns the arr_size
// must not modify current instance
template <typename T>
size_t Array<T>::size(void) const
{
	return (arr_size_);
}
