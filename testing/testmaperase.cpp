/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmaperase.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 14:49:03 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/26 15:21:47 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "./includes/Map.hpp"

void	stdmaperase(void)
{
	std::map<int, int>	m;
	std::pair<int, int>	pair1(10, 0);
	std::pair<int, int>	pair2(5, 0);
	std::pair<int, int>	pair3(17, 0);
	std::pair<int, int>	pair4(2, 0);
	std::pair<int, int>	pair5(20, 0);
	std::pair<int, int>	pair6(9, 0);
	std::pair<int, int>	pair7(12, 0);
	std::pair<int, int>	pair8(3, 0);
	std::pair<int, int>	pair9(11, 0);
	std::pair<int, int>	pair10(18, 0);
	std::pair<int, int>	pair11(15, 0);
	std::pair<int, int>	pair12(30, 0);
	std::pair<int, int>	pair13(13, 0);
	std::pair<int, int>	pair14(33, 0);

	m.insert(pair1);
	m.insert(pair2);
	m.insert(pair3);
	m.insert(pair4);
	m.insert(pair5);
	m.insert(pair6);
	m.insert(pair7);
	m.insert(pair8);
	m.insert(pair9);
	m.insert(pair10);
	m.insert(pair11);
	m.insert(pair12);
	m.insert(pair13);
	m.insert(pair14);

	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first << "\t";
	}
	std::cout << std::endl;

	std::map<int, int>::iterator del = m.begin();
	del++;
	std::cout << (*m.begin()).first << ' ' << (*del).first << std::endl;

	m.erase(m.begin(), del);
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first << "\t";
	}
	std::cout << std::endl;
}

void	ftmaperase(void)
{
	ft::map<int, int>	m;
	ft::pair<int, int>	pair1(10, 0);
	ft::pair<int, int>	pair2(5, 0);
	ft::pair<int, int>	pair3(17, 0);
	ft::pair<int, int>	pair4(2, 0);
	ft::pair<int, int>	pair5(20, 0);
	ft::pair<int, int>	pair6(9, 0);
	ft::pair<int, int>	pair7(12, 0);
	ft::pair<int, int>	pair8(3, 0);
	ft::pair<int, int>	pair9(11, 0);
	ft::pair<int, int>	pair10(18, 0);
	ft::pair<int, int>	pair11(15, 0);
	ft::pair<int, int>	pair12(30, 0);
	ft::pair<int, int>	pair13(13, 0);
	ft::pair<int, int>	pair14(33, 0);

	m.insert(pair1);
	m.insert(pair2);
	m.insert(pair3);
	m.insert(pair4);
	m.insert(pair5);
	m.insert(pair6);
	m.insert(pair7);
	m.insert(pair8);
	m.insert(pair9);
	m.insert(pair10);
	m.insert(pair11);
	m.insert(pair12);
	m.insert(pair13);
	m.insert(pair14);

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first << "\t";
	}
	std::cout << std::endl;

	ft::map<int, int>::iterator del = m.begin();
	del++;
	std::cout << (*m.begin()).first << ' ' << (*del).first << std::endl;

	m.erase(m.begin(), del);
	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first << "\t";
	}
	std::cout << std::endl;
}

int	main(void)
{
	stdmaperase();
	ftmaperase();
	return (0);
}
