/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiman-m <maiman-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:27:08 by maiman-m          #+#    #+#             */
/*   Updated: 2024/04/19 13:49:21 by maiman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	FORMAT_TEST("N × 2 TEST");
	const int arr_pos[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	iter(arr_pos, arr_size(arr_pos), multiply_by_two);
	std::cout << std::endl;

	FORMAT_TEST("N - 1 TEST");
	const int arr_neg[] = {-1, -3, -5, -7, -9, -11, -13, -15, -17};
	iter(arr_neg, arr_size(arr_neg), decrement_by_one);
	std::cout << std::endl;

	FORMAT_TEST ("LAST CHARACTER TEST");
	std::string arr_word[] = {"tarantula", "crab", "cadillac", "yard", "jungle"};
	iter(arr_word, arr_size(arr_word), print_last_char);
	std::cout << std::endl;
}
