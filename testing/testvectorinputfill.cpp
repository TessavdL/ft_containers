/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testvectorinputfill.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 16:24:53 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/15 16:44:08 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "./includes/Vector.hpp"

void	original_vector(void)
{
	std::vector<int>	fill(10, 42);

	for (std::vector<int>::iterator it = fill.begin(); it != fill.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::vector<int>	insertv(fill.begin(), fill.end());

	for (std::vector<int>::iterator it = insertv.begin(); it != insertv.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::vector<int>	empty;

	empty.insert(empty.begin(), insertv.begin(), insertv.end());
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
}

void	my_vector(void)
{
	ft::vector<int>	fill(10, 42);

	for (ft::vector<int>::iterator it = fill.begin(); it != fill.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	ft::vector<int>	insertv(fill.begin(), fill.end());

	for (ft::vector<int>::iterator it = insertv.begin(); it != insertv.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	ft::vector<int>	empty;

	std::cout << std::boolalpha << empty.empty() << std::endl;
	empty.insert(empty.begin(), insertv.begin(), insertv.end());
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
	std::cout << std::boolalpha << empty.empty() << std::endl;
}

int	main(void)
{
	original_vector();
	my_vector();
	return (0);
}