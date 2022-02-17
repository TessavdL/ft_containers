/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 17:09:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/27 17:24:05 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair
{
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	typedef T1	first_type;
	typedef T2	second_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	first_type	first;
	second_type	second;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// ------------------------------CONSTRUCTORS-------------------------------
	pair(void) : first(), second() {}

	pair(const first_type& a, const second_type& b) : first(a), second(b) {}

	template<class U, class V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

	// -------------------------------DESTRUCTOR--------------------------------
	~pair(void) {}

	// ---------------------------ASSIGNMENT OPERATOR---------------------------
	pair&	operator=(const pair& pr)
	{
		if (this != &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}
		return (*this);
	}
};

// ~~~~~~~~~~~~~~~~~~~~~~~~NON-MEMBER FUNCTION OVERLOADS~~~~~~~~~~~~~~~~~~~~~~~~
template <class T1, class T2>
bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs < lhs));
}

template <class T1, class T2>
bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (lhs.first > rhs.first || (!(rhs.first > lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs < rhs));
}

}	// end of namespace ft

#endif
