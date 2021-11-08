/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testreverseiteratormap.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/30 14:51:17 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/30 16:20:53 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "./includes/Map.hpp"

int	main(void)
{
	ft::map<int, int>	ftmap;
	ft::map<int, int>::iterator	ftlower_bound;
	ft::map<int, int>::iterator	ftlower_bound_empty;
	ft::map<int, int>::iterator	ftlower_bound_illegal;
	ft::pair<const int, int> ftpair(0 ,1);
	ft::pair<const int, int> ftpair2(2, 3);
	ft::pair<const int, int> ftpair3(4, 5);

	ftmap.insert(ftpair);
	ftmap.insert(ftpair2);
	ftmap.insert(ftpair3);

	for (ft::map<int, int>::iterator it = ftmap.begin(); it != ftmap.end(); it++)
		std::cout << (*it).first << std::endl;;
	std::cout << std::endl;

	for (ft::map<int, int>::reverse_iterator rit = ftmap.rbegin(); rit != ftmap.rend(); rit++)
		std::cout << (*rit).first << std::endl;
	std::cout << std::endl;

	ft::map<int, int>::const_iterator cbegin = ftmap.begin();
	ft::map<int, int>::const_iterator cend = ftmap.end();
	for (; cbegin != cend; cbegin++)
		std::cout << (*cbegin).first << std::endl;;
	std::cout << std::endl;

	// for (ft::map<int, int>::const_reverse_iterator rit = ftmap.rbegin(); rit != ftmap.rend(); rit++)
	// 	std::cout << (*rit).first << std::endl;
	// std::cout << std::endl;

	return (0);
}