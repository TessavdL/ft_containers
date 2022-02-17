/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmapupperbound.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 14:02:35 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/21 16:06:31 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "./includes/Map.hpp"

void	stdmapupperbound(void)
{
	std::map<int, int>	m;
	std::map<int, int>::iterator	upper_bound;
	std::map<int, int>::iterator	upper_bound_empty;
	std::map<int, int>::iterator	upper_bound_illegal;
	std::pair<const int, int> pair(0 ,1);
	std::pair<const int, int> pair2(2, 3);
	std::pair<const int, int> pair3(4, 5);
	
	upper_bound_empty = m.upper_bound(1);
	if (upper_bound_empty == m.end())
	{
		std::cout << "calling upper_bound on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	upper_bound_illegal = m.upper_bound(4);
	if (upper_bound_illegal == m.end())
	{
		std::cout << "calling upper_bound on a non empty container equal to most_right returns m.end()" << std::endl;
	}

	upper_bound = m.upper_bound(0);
	std::cout << "upper_bound with existing key 0 = " << (*upper_bound).first << std::endl;

	upper_bound = m.upper_bound(2);
	std::cout << "upper_bound with existing key 2 = " << (*upper_bound).first << std::endl;

	upper_bound = m.upper_bound(-1);
	std::cout << "upper_bound with non-existing key -1 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;

	upper_bound = m.upper_bound(1);
	std::cout << "upper_bound with non-existing key 1 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;

	upper_bound = m.upper_bound(3);
	std::cout << "upper_bound with non-existing key 3 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;
}

void	ftmapupperbound(void)
{
	ft::map<int, int>	m;
	ft::map<int, int>::iterator	upper_bound;
	ft::map<int, int>::iterator	upper_bound_empty;
	ft::map<int, int>::iterator	upper_bound_illegal;
	ft::pair<const int, int> pair(0 ,1);
	ft::pair<const int, int> pair2(2, 3);
	ft::pair<const int, int> pair3(4, 5);
	
	upper_bound_empty = m.upper_bound(1);
	if (upper_bound_empty == m.end())
	{
		std::cout << "calling upper_bound on an empty container returns m.end()" << std::endl;
	}

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << "\t";
	std::cout << std::endl;

	upper_bound_illegal = m.upper_bound(4);
	if (upper_bound_illegal == m.end())
	{
		std::cout << "calling upper_bound on a non empty container equal to most_right returns m.end()" << std::endl;
	}

	upper_bound = m.upper_bound(0);
	std::cout << "upper_bound with existing key 0 = " << (*upper_bound).first << std::endl;

	upper_bound = m.upper_bound(2);
	std::cout << "upper_bound with existing key 2 = " << (*upper_bound).first << std::endl;

	upper_bound = m.upper_bound(-1);
	std::cout << "upper_bound with non-existing key -1 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;

	upper_bound = m.upper_bound(1);
	std::cout << "upper_bound with non-existing key 1 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;

	upper_bound = m.upper_bound(3);
	std::cout << "upper_bound with non-existing key 3 =\t" << (*upper_bound).first << " " << (*upper_bound).second << std::endl;
}

int	main(void)
{
	stdmapupperbound();
	ftmapupperbound();
	return (0);
}
