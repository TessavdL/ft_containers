/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testisintegral.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 19:38:43 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/18 10:11:15 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>
#include "./includes/TypeTraits.hpp"

int main() {
	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << std::is_integral<char>::value << std::endl;
	std::cout << "int: " << std::is_integral<int>::value << std::endl;
	std::cout << "float: " << std::is_integral<float>::value << std::endl;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	return 0;
}
