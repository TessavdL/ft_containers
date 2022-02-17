/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testreverseiteratormap.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 14:51:17 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/25 15:54:17 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "./includes/Map.hpp"

void	stdmapiterators(void)
{
	std::map<int, int>			m;
	std::pair<const int, int>	pair(0 ,1);
	std::pair<const int, int>	pair2(2, 3);
	std::pair<const int, int>	pair3(4, 5);

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	for (std::map<int, int>::const_iterator c_it = m.begin(); c_it != m.end(); c_it++)
		std::cout << (*c_it).first << ' ' << (*c_it).second << '\t';
	std::cout << std::endl;

	for (std::map<int, int>::reverse_iterator r_it = m.rbegin(); r_it != m.rend(); r_it++)
		std::cout << (*r_it).first << ' ' << (*r_it).second << '\t';
	std::cout << std::endl;

	for (std::map<int, int>::const_reverse_iterator cr_it = m.rbegin(); cr_it != m.rend(); cr_it++)
		std::cout << (*cr_it).first << ' ' << (*cr_it).second << '\t';
	std::cout << std::endl;

	std::map<int, int>::iterator				it;
	std::map<int, int>::const_iterator			c_it;
	std::map<int, int>::reverse_iterator		r_it;
	std::map<int, int>::const_reverse_iterator	cr_it;

	for (it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	for (c_it = m.begin(); c_it != m.end(); c_it++)
		std::cout << (*c_it).first << ' ' << (*c_it).second << '\t';
	std::cout << std::endl;

	for (r_it = m.rbegin(); r_it != m.rend(); r_it++)
		std::cout << (*r_it).first << ' ' << (*r_it).second << '\t';
	std::cout << std::endl;

	for (cr_it = m.rbegin(); cr_it != m.rend(); cr_it++)
		std::cout << (*cr_it).first << ' ' << (*cr_it).second << '\t';
	std::cout << std::endl;
}

void	ftmapiterators(void)
{
	ft::map<int, int>			m;
	ft::pair<const int, int>	pair(0 ,1);
	ft::pair<const int, int>	pair2(2, 3);
	ft::pair<const int, int>	pair3(4, 5);

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	for (ft::map<int, int>::const_iterator c_it = m.begin(); c_it != m.end(); c_it++)
		std::cout << (*c_it).first << ' ' << (*c_it).second << '\t';
	std::cout << std::endl;

	for (ft::map<int, int>::reverse_iterator r_it = m.rbegin(); r_it != m.rend(); r_it++)
		std::cout << (*r_it).first << ' ' << (*r_it).second << '\t';
	std::cout << std::endl;

	for (ft::map<int, int>::const_reverse_iterator cr_it = m.rbegin(); cr_it != m.rend(); cr_it++)
		std::cout << (*cr_it).first << ' ' << (*cr_it).second << '\t';
	std::cout << std::endl;

	ft::map<int, int>::iterator					it;
	ft::map<int, int>::const_iterator			c_it;
	ft::map<int, int>::reverse_iterator			r_it;
	ft::map<int, int>::const_reverse_iterator	cr_it;

	for (it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << ' ' << (*it).second << '\t';
	std::cout << std::endl;

	for (c_it = m.begin(); c_it != m.end(); c_it++)
		std::cout << (*c_it).first << ' ' << (*c_it).second << '\t';
	std::cout << std::endl;

	for (r_it = m.rbegin(); r_it != m.rend(); r_it++)
		std::cout << (*r_it).first << ' ' << (*r_it).second << '\t';
	std::cout << std::endl;

	for (cr_it = m.rbegin(); cr_it != m.rend(); cr_it++)
		std::cout << (*cr_it).first << ' ' << (*cr_it).second << '\t';
	std::cout << std::endl;
}

int	main(void)
{
	stdmapiterators();
	ftmapiterators();
	return (0);
}
