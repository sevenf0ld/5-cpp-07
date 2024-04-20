/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:34:06 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/20 15:47:33 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zero_two.hh"

#include <cstdlib>
#include <ctime>
#define MAX_VAL 750

int test_subject_file(void)
{
	flag = 0;
	FORMAT_TEST("SUBJECT PDF TEST");

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

void print_element(size_t size, Array<double> const &obj)
{
	flag = 0;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << obj[i];
		if (i + 1 != size)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void intro(const char *format, size_t size, Array<double> const &obj)
{
	flag = 0;

	FORMAT_TEST(format);
	std::cout << AC_YELLOW << "size of obj passed in as param is " << size << "." << AC_NORMAL << std::endl;
	std::cout << "elements of obj passed in as param is ";
	print_element(size, obj);
	std::cout << std::endl;
}

void test_default(void)
{
	flag = 0;
	FORMAT_TEST("DEFAULT CONSTRUCTOR TEST");

	Array<double>def;
	std::cout << std::endl;

	try
	{
		std::cout << "accessing element at index " << 0 << " gives the value "
				  << def[0] << std::endl;
	}
	catch (std::out_of_range &e)
	{
		ACCESS_ERR(e.what());
	}
	std::cout << std::endl;
}

void test_param(Array<double> const &obj)
{
	flag = 0;
	intro("PARAMETERIZED CONSTRUCTOR TEST", obj.size(), obj);

	try
	{
		std::cout << "accessing element at index " << ARR_SIZE << " gives the value "
				  << obj[ARR_SIZE] << std::endl;
	}
	catch (std::out_of_range &e)
	{
		ACCESS_ERR(e.what());
	}
	std::cout << std::endl;

	std::cout << "accessing element at index " << ARR_SIZE - 1 << " gives the value "
			  << obj[ARR_SIZE - 1] << std::endl;
	std::cout << std::endl;
}

void test_copy(Array<double> &obj)
{
	flag = 0;
	intro("COPY CONSTRUCTOR TEST", obj.size(), obj);

	obj[2] = 1;
	obj[3] = 2;

	const Array<double>copy(obj);
	std::cout << std::endl;

	std::cout << "elements of copy is ";
	print_element(copy.size(), copy);
	std::cout << std::endl;

	FORMAT_TEST("CONST TEST");
	flag = 1;
	std::cout << "reading from (const) element at index 2..." << std::endl
			  << "copy[2]: " << AC_CYAN << copy[2] << AC_NORMAL << std::endl;
	std::cout << std::endl;
	// error: assignment of read-only location
	//copy[2] = 3;
}

void test_assign(Array<double> &obj)
{
	flag = 0;
	intro("ASSIGNMENT OPERATOR TEST", obj.size(), obj);

	obj[2] = 3;
	obj[3] = 4;

	Array<double>assign;
	assign = obj;
	std::cout << std::endl;

	std::cout << "elements of assign is ";
	print_element(assign.size(), assign);
	std::cout << std::endl;

	FORMAT_TEST("NON-CONST TEST");
	flag = 1;
	std::cout << "reading from (non-const) element at index 2..." << std::endl
			  << "assign[2]: "  << AC_CYAN << assign[2] << AC_NORMAL << std::endl;
	std::cout << std::endl;

	assign[2] = 5;
	flag = 1;
	std::cout << "writing to (non-const) element at index 2..." << std::endl
			  << "assign[2]: " << AC_CYAN << assign[2] << AC_NORMAL << std::endl;
	std::cout << std::endl;

	std::cout << "elements of assign is updated to ";
	print_element(assign.size(), assign);
	std::cout << std::endl;
}

void test_ctor(void)
{
	flag = 0;
	test_default();
	std::cout << std::endl;

	//Array<double>param(ARR_SIZE);
	std::cout << std::endl;

	//test_param(param);
	std::cout << std::endl;

	//test_copy(param);
	std::cout << std::endl;

	//test_assign(param);
}

int main(void)
{
	//test_subject_file();
	std::cout << std::endl;

	test_ctor();
	std::cout << std::endl;
}
