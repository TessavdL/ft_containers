/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testvectorinsert.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 13:45:25 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/03 19:08:05 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "./includes/Vector.hpp"

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

	for (ft::vector<int>::const_iterator it = empty.begin(); it != empty.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

}

int main(void)
{
	original_vector();
	my_vector();
	return (0);
}
