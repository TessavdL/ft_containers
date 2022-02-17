/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmaplowerbound.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 13:04:32 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/21 15:49:17 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "./includes/Map.hpp"

void	stdmaplowerbound(void)
{
	std::map<int, int>	m;
	std::map<int, int>::iterator	lower_bound;
	std::map<int, int>::iterator	lower_bound_empty;
	std::map<int, int>::iterator	lower_bound_illegal;
	std::pair<const int, int> pair(0 ,1);
	std::pair<const int, int> pair2(2, 3);
	std::pair<const int, int> pair3(4, 5);
	
	lower_bound_empty = m.lower_bound(1);
	if (lower_bound_empty == m.end())
	{
		std::cout << "calling lower_bound on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	lower_bound_illegal = m.lower_bound(6);
	if (lower_bound_illegal == m.end())
	{
		std::cout << "calling lower_bound on a non empty container with key bigger than most_right returns m.end()" << std::endl;
	}

	lower_bound = m.lower_bound(0);
	std::cout << "lower_bound with existing key 0 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(2);
	std::cout << "lower_bound with existing key 2 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(4);
	std::cout << "lower_bound with existing key 4 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(-1);
	std::cout << "lower_bound with non-existing key -1 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;

	lower_bound = m.lower_bound(1);
	std::cout << "lower_bound with non-existing key 1 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;

	lower_bound = m.lower_bound(3);
	std::cout << "lower_bound with non-existing key 3 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;
}

void	ftmaplowerbound(void)
{
	ft::map<int, int>	m;
	ft::map<int, int>::iterator	lower_bound;
	ft::map<int, int>::iterator	lower_bound_empty;
	ft::map<int, int>::iterator	lower_bound_illegal;
	ft::pair<const int, int> pair(0 ,1);
	ft::pair<const int, int> pair2(2, 3);
	ft::pair<const int, int> pair3(4, 5);
	
	lower_bound_empty = m.lower_bound(1);
	if (lower_bound_empty == m.end())
	{
		std::cout << "calling lower_bound on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	lower_bound_illegal = m.lower_bound(6);
	if (lower_bound_illegal == m.end())
	{
		std::cout << "calling lower_bound on a non empty container with key bigger than most_right returns m.end()" << std::endl;
	}

	lower_bound = m.lower_bound(0);
	std::cout << "lower_bound with existing key 0 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(2);
	std::cout << "lower_bound with existing key 2 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(4);
	std::cout << "lower_bound with existing key 4 = " << (*lower_bound).first << std::endl;

	lower_bound = m.lower_bound(-1);
	std::cout << "lower_bound with non-existing key -1 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;

	lower_bound = m.lower_bound(1);
	std::cout << "lower_bound with non-existing key 1 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;

	lower_bound = m.lower_bound(3);
	std::cout << "lower_bound with non-existing key 3 =\t" << (*lower_bound).first << " " << (*lower_bound).second << std::endl;
}

int	main(void)
{
	stdmaplowerbound();
	ftmaplowerbound();
	return (0);
}
