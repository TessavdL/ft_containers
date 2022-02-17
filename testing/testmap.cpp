/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmap.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 17:41:27 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/03 17:39:49 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Map.hpp"
#include "./includes/Pair.hpp"
#include <map>
#include <iostream>

int main(void)
{
	ft::map<int, int> m;
	ft::pair<const int, int> pair(0 ,1);
		ft::pair<const int, int> pair2(2, 3);
			ft::pair<const int, int> pair3(4, 5);

	m.insert(pair);
	m.insert(pair2);
	m.insert(pair3);

	size_t size = m.size();
	std::cout << "size = " << size << std::endl << std::endl;

	// ----------------------------------------------------------------------------

	for (ft::map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
	std::cout << std::endl;

	for (ft::map<int,int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << std::endl;
	}

	// ----------------------------------------------------------------------------

	// for (ft::map<int,int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
	// {
	// 	std::cout << it->first << std::endl;
	// }
	// std::cout << std::endl;

	// ----------------------------------------------------------------------------


	ft::map<int, int>	m_test_brackets;

	m_test_brackets[1];
	std::cout << "default value of m[1] = " << m_test_brackets[1] << std::endl;
	m_test_brackets[1] = 2;
	std::cout << "value of m[1] after assignment = " << m_test_brackets[1] << std::endl << std::endl;

	// ----------------------------------------------------------------------------


	// mit = m.begin();
	// m.erase(mit->first);
	// size = m.size();
	// std::cout << "size = " << size << std::endl;

	// for (ft::map<int,int>::iterator it = m.begin(); size > 0; size--)
	// {
	// 	std::cout << it->first << std::endl;
	// 	it++;
	// }

	// mit = m.begin();
	// m.erase(mit->first);
	// size = m.size();
	// std::cout << "size = " << size << std::endl;

	// if (m.empty() == true)
	// {
	// 	std::cout << "map is empty" << std::endl;
	// }
	// return (0);
}


	// std::map<int,int> empty;

	// std::map<int,int>::iterator ret = empty.find(4);
	// if (ret == empty.end())
	// 	std::cout << "empty" << std::endl;

	// std::map<int, int> m;

	// m.insert({1, 1});
	// m.insert({2, 2});

	// std::map<int, int>::iterator it = m.begin();

	// std::cout << (*it).first << std::endl;
	// std::cout << it->first << std::endl;