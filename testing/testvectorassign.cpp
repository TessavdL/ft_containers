/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testvectorassign.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 18:03:32 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/30 15:36:18 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Vector.hpp"
#include <vector>
#include <iostream>

void	stdvectorassign(void)
{
	std::vector<int>			v;
	std::vector<int>			v2;
	std::vector<int>::iterator	Iter;

	for (size_t i = 1; i < 6; i++)
		v.push_back(2 * i + 1);

	for (size_t i = 1; i < 20; i++)
		v2.push_back(2 * i + 1);

	for (Iter = v.begin(); Iter != v.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	// throws exception
	// v.assign(v2.end(), v2.begin());
	// v.assign(-1, 42);
	// v.insert(v.begin(), -1, 42);
	// v.insert(v.begin(), v.end(), v.begin());
	// v.resize(-1, 42);

	// segfaults
	// v.erase(v.end(), v.begin());

	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.resize(33, 42);
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	std::cout << "size = " << v2.size() << std::endl;
	v2.erase(v2.begin());
	std::cout << "size after erase 1 = " << v2.size() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end() + 1; Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	std::cout << "size = " << v2.size() << std::endl;
	v2.erase(v2.begin(), v2.begin() + 5);
	std::cout << "size = " << v2.size() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	std::vector<int>	one;

	one.push_back(1);

	one.erase(one.begin());

	for (std::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	one.push_back(2);
	one.push_back(3);
	one.push_back(4);
	one.push_back(5);

	std::vector<int>::iterator test;

	test = one.erase(one.begin(), one.begin() + 1);

	for (test = one.begin(); test != one.end(); test++)
		std::cout << *test << "\t";
	std::cout << std::endl;

	for (std::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	test = one.erase(one.begin() + 1, one.begin() + 2);

	for (test = one.begin(); test != one.end(); test++)
		std::cout << *test << "\t";
	std::cout << std::endl;

	for (std::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << std::endl;
}

void	ftvectorassign(void)
{
	ft::vector<int>				v;
	ft::vector<int>				v2;
	ft::vector<int>::iterator	Iter;

	for (size_t i = 1; i < 6; i++)
		v.push_back(2 * i + 1);

	for (size_t i = 1; i < 20; i++)
		v2.push_back(2 * i + 1);

	for (Iter = v.begin(); Iter != v.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	// throws exception
	// v.assign(v2.end(), v2.begin());
	// v.assign(-1, 42);
	// v.insert(v.begin(), -1, 42);
	// v.insert(v.begin(), v.end(), v.begin());
	// v.resize(-1, 42);

	// segfaults
	// v.erase(v.end(), v.begin());

	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;
	v2.resize(33, 42);
	std::cout << "size = " << v2.size() << std::endl;
	std::cout << "capacity = " << v2.capacity() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	std::cout << "size = " << v2.size() << std::endl;
	v2.erase(v2.begin());
	std::cout << "size after erase 1 = " << v2.size() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end() + 1; Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	std::cout << "size = " << v2.size() << std::endl;
	v2.erase(v2.begin(), v2.begin() + 5);
	std::cout << "size = " << v2.size() << std::endl;

	for (Iter = v2.begin(); Iter != v2.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	ft::vector<int>	one;

	one.push_back(1);

	one.erase(one.begin());

	for (ft::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	one.push_back(2);
	one.push_back(3);
	one.push_back(4);
	one.push_back(5);

	ft::vector<int>::iterator test;

	test = one.erase(one.begin(), one.begin() + 1);

	for (test = one.begin(); test != one.end(); test++)
		std::cout << *test << "\t";
	std::cout << std::endl;

	for (ft::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	test = one.erase(one.begin() + 1, one.begin() + 2);

	for (test = one.begin(); test != one.end(); test++)
		std::cout << *test << "\t";
	std::cout << std::endl;

	for (ft::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << std::endl;
}

int	main(void)
{
	stdvectorassign();
	ftvectorassign();
	return (0);
}
