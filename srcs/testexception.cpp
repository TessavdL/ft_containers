/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testexception.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/24 17:52:10 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/24 18:21:01 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../includes/Vector.hpp"

int	main(void)
{
	std::vector<int>	v;

	for (size_t i = 1; i < 6; i++)
		v.push_back(2 * i + 1);
	try {
		v.at(10);
	}
	catch (const std::out_of_range& range) {
		std::cout << range.what() << std::endl;
	}

	ft::vector<int>				mv;

	for (size_t i = 0; i < v.size(); i++)
		mv.push_back(v[i]);
	try {
		mv.at(10);
	}
	catch (const std::out_of_range& range) {
		std::cout << range.what() << std::endl;
	}
	return (0);
}
