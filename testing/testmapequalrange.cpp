/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmapequalrange.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 16:08:11 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/21 16:30:00 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <iostream>
#include "./includes/Map.hpp"

void	stdmapequalrange(void)
{
	std::map<int, int>			m;
	std::pair<const int, int>	pair(0 ,1);
	std::pair<const int, int>	pair2(2, 3);
	std::pair<const int, int>	pair3(4, 5);

	std::pair<std::map<const int, int>::iterator, std::map<const int, int>::iterator>	equal_range_empty;

	equal_range_empty = m.equal_range(1);

	if (equal_range_empty.first == m.end() && equal_range_empty.second == m.end())
	{
		std::cout << "calling equal_range on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	std::pair<std::map<const int, int>::iterator, std::map<const int, int>::iterator>	equal_range;

	equal_range = m.equal_range(2);

	std::cout << "lower bound points to: ";
	std::cout << equal_range.first->first << " => " << equal_range.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << equal_range.second->first << " => " << equal_range.second->second << '\n';

	std::pair<std::map<const int, int>::iterator, std::map<const int, int>::iterator>	equal_range_illegal;

	equal_range_illegal = m.equal_range(4);

	std::cout << "lower bound points to: ";
	std::cout << equal_range_illegal.first->first << " => " << equal_range_illegal.first->second << '\n';

	if (equal_range_illegal.second == m.end())
	{
		std::cout << "lower bound points to most right pair and upper bound is equal to m.end()" << std::endl;
	}
}

void	ftmapequalrange(void)
{
	ft::map<int, int>			m;
	ft::pair<const int, int>	pair(0 ,1);
	ft::pair<const int, int>	pair2(2, 3);
	ft::pair<const int, int>	pair3(4, 5);

	ft::pair<ft::map<const int, int>::iterator, ft::map<const int, int>::iterator>	equal_range_empty;

	equal_range_empty = m.equal_range(1);

	if (equal_range_empty.first == m.end() && equal_range_empty.second == m.end())
	{
		std::cout << "calling equal_range on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	ft::pair<ft::map<const int, int>::iterator, ft::map<const int, int>::iterator>	equal_range;

	equal_range = m.equal_range(2);

	std::cout << "lower bound points to: ";
	std::cout << equal_range.first->first << " => " << equal_range.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << equal_range.second->first << " => " << equal_range.second->second << '\n';

	ft::pair<ft::map<const int, int>::iterator, ft::map<const int, int>::iterator>	equal_range_illegal;

	equal_range_illegal = m.equal_range(4);

	std::cout << "lower bound points to: ";
	std::cout << equal_range_illegal.first->first << " => " << equal_range_illegal.first->second << '\n';

	if (equal_range_illegal.second == m.end())
	{
		std::cout << "lower bound points to most right pair and upper bound is equal to m.end()" << std::endl;
	}
}

int	main(void)
{
	stdmapequalrange();
	ftmapequalrange();
	return (0);
}
