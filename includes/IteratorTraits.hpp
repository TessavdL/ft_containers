/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IteratorTraits.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 15:26:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 13:23:21 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

struct input_iterator_tag {};

struct output_iterator_tag {};

struct forward_iterator_tag : public input_iterator_tag {};

struct bidirectional_iterator_tag : public forward_iterator_tag {};

struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// _special_reference_check is a struct that is necessary in has_iterator_member_types, because typename U::reference* does not work
template <class>
struct _special_reference_check
{
	typedef void	type;
};

// has_iterator_member_types::value is true if the iterator has all member types
template <class T>
struct has_iterator_member_types
{
	private:
		typedef char	true_type;
		typedef int		false_type;
		template <class U>
		static true_type _test(	typename U::iterator_category* = 0,
								typename U::difference_type* = 0,
								typename U::value_type* = 0,
								typename ft::_special_reference_check<typename U::reference>::type* = 0,
								typename U::pointer* = 0);
		template <class U>
		static false_type	_test(...);

	public:
		static const bool	value = sizeof(true_type) == sizeof(_test<T>(0,0,0,0,0));
};

// has_iterator_member_types::value is true if the iterator has an iterator_category
template <class T>
struct has_iterator_category
{
	private:
		typedef char	true_type;
		typedef int		false_type;
		template <class U>
		static true_type	_test(typename U::iterator_category* = 0);
		template <class U>
		static false_type	_test(...);

	public:
		static const bool	value = sizeof(true_type) == sizeof(_test<T>(0));
};

// _iterator traits has no member types defined if the boolean is false
// _iterator traits has all member types defined if the boolean is true
template <bool, class Iterator>
struct _iterator_traits {};

template <class Iterator>
struct _iterator_traits<true, Iterator>
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference 			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

// iterator_traits inherits from _iterator_traits
// based on the value of has_iterator_membery_types::value it will either have all member types defined or none
template <class Iterator>
struct iterator_traits : public _iterator_traits<has_iterator_member_types<Iterator>::value, Iterator> {};

template <class T>
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::random_access_iterator_tag	iterator_category;
};

template <class T>
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef ft::random_access_iterator_tag	iterator_category;
};

}	// end of namespace ft

#endif
