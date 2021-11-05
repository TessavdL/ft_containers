/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IteratorTraits.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 15:26:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/03 20:16:56 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {
	template <typename Iterator>
	struct iterator_traits : public ft::enable_if<ft::has_iterator_category<T>::result, Iterator> {};

	template <typename Iterator>
	struct iterator_traits<Iterator*>
	{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};
}
// namespace ft {
// template <class Iterator>
// class iterator_traits : public enable_if<has_iterator_category<T>::result, T> {};
// {
// 	public:
// 		typedef typename Iterator::difference_type		difference_type;
// 		typedef typename Iterator::value_type			value_type;
// 		typedef typename Iterator::pointer				pointer;
// 		typedef typename Iterator::reference 			reference;
// 		typedef typename Iterator::iterator_category	iterator_category;
// };
// }

namespace ft {
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}

namespace ft {
template <bool, typename T = void>
struct enable_if {};
}

namespace ft {
template <typename T>
struct enable_if<true, T>
{
	typedef T	type;
};
}

namespace ft {
template <typename T>
struct has_iterator_category
{
	private:
		typedef char	true_type;
		typedef int		false_type;
	
		template <class U>
		static true_type	test(typename U::iterator_category* = 0);
		template <class U>
		static false_type	test(...);

	public:
		static const bool result = (sizeof(true_type) == sizeof(test<T>(0)));
};
}

#endif
