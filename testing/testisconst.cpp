/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testisconst.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:50:16 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/21 20:45:39 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
#include "./includes/TypeTraits.hpp"

int main(void)
{
	std::cout << std::boolalpha;
	std::cout << ft::is_const<const int>::value << std::endl;
	std::cout << ft::is_const<int>::value << std::endl;
	std::cout << std::is_const<const int>::value << std::endl;
	std::cout << std::is_const<int>::value << std::endl;
	return (0);
}
