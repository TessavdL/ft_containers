/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 14:16:34 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/30 15:54:43 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// -----------------------------CONSTRUCTOR-----------------------------
		explicit	stack(const container_type& ctnr = container_type()) : c(ctnr) {}

		stack(const stack& other) : c(other.c) {}

		// ------------------------------DESTRUCTOR-----------------------------
		~stack(void) {}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		stack&	operator=(const stack& other)
		{
			if (this != &other)
			{
				this->c = other.c;
			}
			return (*this);
		}

		// -------------------------------CAPACITY------------------------------
		reference	top(void)
		{
			return (this->c.back());
		}

		const_reference	top(void) const
		{
			return (this->c.back());
		}

		// ----------------------------ELEMENT ACCESS---------------------------
		bool	empty(void) const
		{
			return (this->c.empty());
		}

		size_type	size(void) const
		{
			return (this->c.size());
		}

		// ------------------------------MODIFIERS------------------------------
		void	push(const value_type& value)
		{
			this->c.push_back(value);
		}

		void	pop(void)
		{
			this->c.pop_back();
		}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PROTECTED MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~
	protected:
		container_type	c;

};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~NON-MEMBER FUCTION OVERLOADS~~~~~~~~~~~~~~~~~~~~~~~
// ----------------------------RELATIONAL OPERATORS-----------------------------
template <class T, class Container>
bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs == rhs);
}

template <class T, class Container>
bool	operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs != rhs);
}

template <class T, class Container>
bool	operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs < rhs);
}

template <class T, class Container>
bool	operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs > rhs);
}

template <class T, class Container>
bool	operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs >= rhs);
}

template <class T, class Container>
bool	operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (lhs <= rhs);
}

}	// end of namespace ft

#endif
