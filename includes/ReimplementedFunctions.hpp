/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReimplementedFunctions.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 16:11:25 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/13 23:48:56 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REIMPLEMENTED_FUNCTIONS_HPP
# define REIMPLEMENTED_FUNCTIONS_HPP

# include "InputIterator.hpp"
# include "Pair.hpp"

namespace ft {
template <class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 t, T2 u)
{
	ft::pair<T1, T2>	pair(t, u);

	return (pair);
}
}

namespace ft {
template <class InputIterator1, class InputIterator2>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < first2)
			return (true);
	}
	return (first2 != last2); // if first2 is at the end return false (they are equal), of first2 is not at the end return true (first 1 is smaller than first 2, first 2 is longer)
}
}

namespace ft {
template <class InputIterator1, class InputIterator2, class Compare>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (comp(first1, first2))
			return (true);
		if (comp(first2, first1))
			return (false);
	}
	return (first2 != last2); // if first2 is at the end return false (first1 and first2 are equal), of first2 is not at the end return true (first2 is longer, therefore first1 is smaller than first2)
}
}

namespace ft {
template <class InputIterator1, class InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (!(first1 == *first2))
			return (false);
	}
	return (true);
}
}

namespace ft {
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (!pred(*first1, *first2))
			return (false);
	}
	return (true);
}
}

#endif
