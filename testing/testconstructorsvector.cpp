/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testconstructorsvector.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 10:46:12 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/02 11:14:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "./includes/Vector.hpp"
#include <exception>

int	main(void)
{
	std::vector<int>	v_empty;
	std::vector<int>	v(42);

	// std::cout << "capacity = " << v_empty.capacity() << " size = " << v_empty.size() << std::endl;
	try
	{
		v_empty.at(6);
	}
	catch (std::out_of_range const& e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}