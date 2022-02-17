/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testillegalconstructorvector.cpp                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 21:36:56 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 22:28:55 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "./includes/Vector.hpp"

int	main(void)
{
	// terminate will be called after std::vector throws an instance of std::length_error
	// std::vector<int>	v(-1, -1);

	// std::cout << "size = " << v.size() << std::endl;

	// terminate will be called after ft::vector throws an instance of std::length_error
	// ft::vector<int>	mv(-1, -1);

	// std::cout << "size = " << mv.size() << std::endl;
	return (0);
}
