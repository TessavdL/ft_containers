/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmapinsertpos.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 17:21:00 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/26 17:39:38 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "./includes/Map.hpp"

void	stdmapiterators(void)
{
	std::map<int, int>			m;
	std::map<int, int>			m2;
	std::pair<const int, int>	pair(0 ,1);
	std::pair<const int, int>	pair2(2, 3);
	std::pair<const int, int>	pair3(4, 5);

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	std::pair<const int, int>	pair4(42, 42);

	m.insert(m.begin(), pair4);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	std::pair<const int, int>	pair5(1, 2);

	m.insert(m.begin(), pair5);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	std::pair<const int, int>	pair6(3, 4);

	m2.insert(pair);
	m2.insert(pair2);
	m2.insert(pair3);

	m.insert(m2.begin(), pair6);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;
}

void	ftmapiterators(void)
{
	ft::map<int, int>			m;
	ft::map<int, int>			m2;
	ft::pair<const int, int>	pair(0 ,1);
	ft::pair<const int, int>	pair2(2, 3);
	ft::pair<const int, int>	pair3(4, 5);

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	ft::pair<const int, int>	pair4(42, 42);

	m.insert(m.begin(), pair4);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	ft::pair<const int, int>	pair5(1, 2);

	m.insert(m.begin(), pair5);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	ft::pair<const int, int>	pair6(3, 4);

	m2.insert(pair);
	m2.insert(pair2);
	m2.insert(pair3);

	m.insert(m2.begin(), pair6);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;
}

int	main(void)
{
	stdmapiterators();
	std::cout << std::endl;
	ftmapiterators();
	return (0);
}