/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testsfinae.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 11:48:46 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/21 20:45:13 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Pair.hpp"
#include <iostream>
#include "../includes/Vector.hpp"
#include "../includes/RandomAccessIterator.hpp"
#include "../includes/IteratorTraits.hpp"

namespace ft {
template<class T>
class pair_traits
{
	typedef typename T::first_type	first_type;
	typedef typename T::second_type	second_type;
};

template<class T>
class is_pair
{
	private:
		typedef char	true_type;
		typedef int		false_type;

		template <class U>
		static true_type	test(typename U::first_type* = 0, typename U::second_type* = 0);
		template <class U>
		static false_type	test(...);
	public:
		static const bool	result = sizeof(true_type) == sizeof(test<T>(0, 0));
};
}

void	print_hello(int n)
{
	std::cout << n << std::endl;
	return ;
}

template<class T>
void	print_hello(T h, typename ft::enable_if<ft::is_pair<T>::result, T>::type* = 0)
{
	std::cout << "hello" << std::endl;
	std::cout << h.first << std::endl;
	std::cout << h.second << std::endl;
}

int	main(void)
{
	ft::pair<int, int> p(0, 1);

	std::cout << std::boolalpha << ft::is_pair<ft::pair<int, int> >::result << std::endl;
	print_hello(p);
	print_hello(0);
	std::cout << std::boolalpha << ft::has_iterator_category<ft::vector<int>::iterator>::value << std::endl;
	std::cout << std::boolalpha << ft::has_iterator_member_types<ft::vector<int>::iterator>::value << std::endl;
	std::cout << std::boolalpha << ft::has_iterator_category<RandomAccessIterator<int> >::value << std::endl;
	std::cout << std::boolalpha << ft::has_iterator_member_types<RandomAccessIterator<int> >::value << std::endl;

	return (0);
}
