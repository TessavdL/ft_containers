/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 17:09:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/21 16:19:10 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

template <class T1, class T2>
class Pair
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
		Pair(void)
		{
			return ;
		}
		Pair(const first_type& a, const second_type& b)
		{
			this->first = a;
			this->second = b;
			return ;
		}
		template<class U, class v>
		Pair(const Pair<U, V>& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~Pair(void)
		{
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		Pair&	operator=(const Pair& pr)
		{
			if (this != &other)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
};



// ~~~~~~~~~~~~~~~~~~~~~~~~NON-MEMBER FUNCTION OVERLOADS~~~~~~~~~~~~~~~~~~~~~~~~
template <class T1, class T2>
bool	operator==(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return (true);
	else
		return (false);
}

template <class T1, class T2>
bool	operator!=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool	operator<(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool	operator<=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool	operator>(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool	operator>=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
{
	return (!(lhs < rhs));
}

#endif
