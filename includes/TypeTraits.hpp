/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TypeTraits.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/18 09:21:42 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/25 15:10:48 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS
# define TYPE_TRAITS

namespace ft {

template <class T, T v>
struct integral_constant {
	typedef T						value_type;
	typedef integral_constant<T,v>	type;
	static const value_type			value = v;
};

typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;

template<typename>
struct is_integral : public false_type {};

template<>
struct is_integral<bool> : public true_type {};

template<>
struct is_integral<char> : public true_type {};

template<>
struct is_integral<wchar_t> : public true_type {};

template<>
struct is_integral<signed char> : public true_type {};

template<>
struct is_integral<short int> : public true_type {};

template<>
struct is_integral<int> : public true_type {};

template<>
struct is_integral<long int> : public true_type {};

template<>
struct is_integral<unsigned char> : public true_type {};

template<>
struct is_integral<unsigned short int> : public true_type {};

template<>
struct is_integral<unsigned int> : public true_type {};

template<>
struct is_integral<unsigned long int> : public true_type {};

template<class T>
struct is_const : public false_type {};

template<class T>
struct is_const<const T> : public true_type {};

// enable_if::type is defined if condition B is true
// enable_if has no member type if condition B is false
template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T	type;
};

}	// end of namespace ft

#endif
