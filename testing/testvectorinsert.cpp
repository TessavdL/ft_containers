/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testvectorinsert.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 13:45:25 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 21:57:16 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "./includes/Vector.hpp"
#include <string>

void	original_vector(void)
{
	std::vector<int>	fill(10, 42);

	fill.insert(fill.begin(), 1);
	for (std::vector<int>::iterator it = fill.begin(); it != fill.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;	

	std::vector<int>	empty;

	std::vector<int>	v(10, 42);
	v.insert(v.begin(), 1);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert on an empty container" << std::endl;
	empty.insert(empty.begin(), 1);
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert at end" << std::endl;
	empty.insert(empty.end(), 4);
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert in the middle" << std::endl;
	empty.insert(empty.begin() + 1, 2);
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert in the middle" << std::endl;
	empty.insert(empty.end() - 1, 3);
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	empty.resize(0);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "size = " << empty.size() << std::endl;
	if (empty.empty() == true)
	{
		std::cout << "Container is empty" << std::endl;
	}

	std::cout << "Calling fill insert" << std::endl;
	empty.insert(empty.begin(), 5, 5);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin(), 2, 2);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin() + 2, 3, 3);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin() + 5, 4, 4);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "Calling single element insert" << std::endl;
	std::vector<int>::iterator pos = empty.insert(empty.begin(), 1);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << *pos << std::endl;
	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "size = " << empty.size() << std::endl;
	std::cout << std::endl << std::endl;
}

void	my_vector(void)
{
	ft::vector<int>	fill(10, 42);

	fill.insert(fill.begin(), 1);
	for (ft::vector<int>::iterator it = fill.begin(); it != fill.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	ft::vector<int>	v(10, 42);
	v.insert(v.begin(), 1);
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	ft::vector<int>	empty;

	std::cout << "Calling insert on an empty container" << std::endl;
	empty.insert(empty.begin(), 1);
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert at end" << std::endl;
	empty.insert(empty.end(), 4);
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert in the middle" << std::endl;
	empty.insert(empty.begin() + 1, 2);
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	std::cout << "Calling insert in the middle" << std::endl;
	empty.insert(empty.end() - 1, 3);
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	empty.resize(0);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "size = " << empty.size() << std::endl;
	if (empty.empty() == true)
	{
		std::cout << "Container is empty" << std::endl;
	}

	std::cout << "Calling fill insert" << std::endl;
	empty.insert(empty.begin(), 5, 5);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin(), 2, 2);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin() + 2, 3, 3);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	empty.insert(empty.begin() + 5, 4, 4);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "Calling single element insert" << std::endl;
	ft::vector<int>::iterator pos = empty.insert(empty.begin(), 1);
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << *pos << std::endl;
	for (ft::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;
	std::cout << "capacity = " << empty.capacity() << std::endl;
	std::cout << "size = " << empty.size() << std::endl;
	std::cout << std::endl << std::endl;
}

int main(void)
{
	original_vector();
	my_vector();
	return (0);
}
