/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 19:25:44 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/12 17:01:51 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"
#include <vector>

int main(void)
{
	TestClass<int>	TestInt(5);

	TestInt.SetArray(5);
	for (std::ptrdiff_t i = 0; i < 5; i++)
		std::cout << TestInt[i] << std::endl;

	std::cout << *(TestInt.begin()) << std::endl;
	std::cout << *(++TestInt.begin()) << std::endl;
	
	TestClass<int>::iterator it = TestInt.begin();
	std::cout << "start " << *it << std::endl;
	++it;
	std::cout << "prefix increment " << *it << std::endl;
	it++;
	std::cout << "postfix increment " << *it << std::endl;
	--it;
	std::cout << "prefix decrement " << *it << std::endl;
	it--;
	std::cout << "postfix decrement " << *it << std::endl;
	std::cout << "at index 0 " << it[0] << std::endl;
	std::cout << "at index 1 " << it[1] << std::endl;
	std::cout << "at index 2 " << it[2] << std::endl;
	std::cout << "at index 3 " << it[3] << std::endl;
	std::cout << "at index 4 " << it[4] << std::endl;

	// TestClass<int>::iterator it_positive_begin_to_end = TestInt.begin();
	// std::cout << *(it_positive_begin_to_end += 0) << std::endl;
	// for (int i = 0; i < 4 ; i++)
	// 	std::cout << *(it_positive_begin_to_end += 1) << std::endl;
	// TestClass<int>::iterator it_positive_end_to_begin = TestInt.end();
	// for (int i = 0; i < 5 ; i++)
	// 	std::cout << *(it_positive_end_to_begin += -1) << std::endl;

	// TestClass<int>::iterator it_negative_begin_to_end = TestInt.begin();
	// std::cout << *(it_negative_begin_to_end -= 0) << std::endl;
	// for (int i = 0; i < 4; i++)
	// 	std::cout << *(it_negative_begin_to_end -= -1) << std::endl;
	// TestClass<int>::iterator it_negative_end_to_begin = TestInt.end();
	// for (int i = 0; i < 5; i++)
	// 	std::cout << *(it_negative_end_to_begin -= 1) << std::endl;

	// TestClass<int>::iterator it_plus_operator = TestInt.begin();
	// for (int i = 0; i < 5 ; i++)
	// 	std::cout << *(it_plus_operator + i) << std::endl;
	// TestClass<int>::iterator it_negative_operator = TestInt.end();
	// for (int i = 1; i < 6 ; i++)
	// 	std::cout << *(it_negative_operator - i) << std::endl;

	// for (TestClass<int>::iterator it = TestInt.begin(); it != TestInt.end(); it++)
	// 	std::cout << *it << std::endl;
	// for (TestClass<int>::iterator it = TestInt.begin(); it != TestInt.end(); it++)
	// 	*it = 5;
	// for (TestClass<int>::iterator it = TestInt.begin(); it != TestInt.end(); it++)
	// 	std::cout << *it << std::endl;

	// std::vector<int>	OriginalInt(5);

	// int i = 0;
	// for (std::vector<int>::iterator it3 = OriginalInt.begin(); it3 != OriginalInt.end(); it3++, i++)
	// 	*it3 = i;

	// // for (std::vector<int>::iterator it3 = OriginalInt.begin(); it3 != OriginalInt.end(); it3++)
	// // 	std::cout << *it3 << std::endl;
	// // std::vector<int>::iterator it4 = OriginalInt.begin();
	// // for (int i = 0; i < 5; i++)
	// // 	std::cout << *(it4 + i) << std::endl;
	// // bool check = (it4 != it4 + 2);
	// // std::cout << check << std::endl;

	// std::vector<int>::iterator a = OriginalInt.begin();
	// std::vector<int>::iterator b = OriginalInt.end();
	// std::cout << b - a << std::endl;

	// TestClass<int>::iterator aa = TestInt.begin();
	// TestClass<int>::iterator bb = TestInt.end();
	// std::cout << bb - aa << std::endl;


	// for (TestClass<int>::iterator aaa = TestInt.begin(); aaa != TestInt.end(); aaa++)
	// 	std::cout << *aaa << std::endl;
	return (0);
}
