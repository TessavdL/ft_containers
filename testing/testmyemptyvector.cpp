/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmyemptyvector.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 23:26:37 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/02 23:27:30 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Vector.hpp"
#include <exception>

void	check_capacity_stats(ft::vector<int>	v_empty)
{
	std::cout << "capacity = " << v_empty.capacity();
	std::cout <<  " size = " << v_empty.size();
	std::cout << " max_size = " << v_empty.max_size() << std::endl;
	if (v_empty.empty() == true)
	{
		std::cout << "vector is empty" << std::endl;
	}
	else
	{
		std::cout << "vector is not empty" << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	ft::vector<int>	v_empty;

	check_capacity_stats(v_empty);

	std::cout << "MEMBER ACCESS" << std::endl;
	std::cout << "vector::at" << std::endl;
	std::cout << "calling vector::at on empty container throws an exception" << std::endl;
	try
	{
		v_empty.at(0);
	}
	catch (std::out_of_range const& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		v_empty.at(-1);
	}
	catch (std::out_of_range const& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		v_empty.at(6);
	}
	catch (std::out_of_range const& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "vector::operator[]" << std::endl;
	std::cout << "accessing a non-existent element through vector::operator[] is undefined" << std::endl;
	std::cout << "calling vector::operator[] on empty container results in a segfault" << std::endl;
	// std::cout << v_empty[0] << std::endl;
	std::cout << "vector::front" << std::endl;
	std::cout << "accessing a non-existent element through vector::front is undefined" << std::endl;
	std::cout << "calling vector::front on empty container results in a segfault" << std::endl;
	// std::cout << v_empty.front() << std::endl;
	std::cout << "vector::back" << std::endl;
	std::cout << "accessing a non-existent element through vector::back is undefined" << std::endl;
	std::cout << "calling vector::back on empty container results in a segfault" << std::endl;
	// std::cout << v_empty.back() << std::endl;
	std::cout << "vector::data" << std::endl; 
	std::cout << "calling vector::back on empty container is possible, but dereferencing dereferencing results in a segfault" << std::endl;	
	if (v_empty.data() == NULL)
	{
		std::cout << "vector::data() on empty container returns NULL" << std::endl;
	}
	// std::cout << *v_empty.data() << std::endl;
	std::cout << std::endl;

	std::cout << "ITERATORS" << std::endl;
	for (ft::vector<int>::iterator it = v_empty.begin(); it != v_empty.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	for (ft::vector<int>::const_iterator it = v_empty.cbegin(); it != v_empty.cend(); it++)
	{
		std::cout << *it << std::endl;
	}
	for (ft::vector<int>::reverse_iterator it = v_empty.rbegin(); it != v_empty.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	for (ft::vector<int>::const_reverse_iterator it = v_empty.crbegin(); it != v_empty.crend(); it++)
	{
		std::cout << *it << std::endl;
	}
	return (0);
}