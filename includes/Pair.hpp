/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 17:09:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/14 00:26:20 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
template <class T1, class T2>
class pair
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T1	first_type;
		typedef T2	second_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~
		first_type	first;
		second_type	second;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		pair(void) : first(), second()
		{
			return ;
		}
		pair(const first_type& a, const second_type& b) : first(a), second(b)
		{
			return ;
		}
		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
		{
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~pair(void)
		{
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
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
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return (true);
	else
		return (false);
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
bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
	return (!(lhs < rhs));
}
}

#endif
