/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ForwardIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:51:07 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/21 17:07:50 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARD_ITERATOR_HPP
# define FORWARD_ITERATOR_HPP

#include "./RandomAccessIterator.hpp"

template <class T>
class ForwardIterator : public RandomAccessIterator<T>
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;
		typedef std::ptrdiff_t	difference_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		ForwardIterator() : RandomAccessIterator<T>()
		{
			std::cout << "Default Constructor of FI called" << std::endl;
			return ;
		}
		//parameter
		ForwardIterator(pointer ptr) : RandomAccessIterator<T>(ptr)
		{
			std::cout << "Parameter Constructor of FI called" << std::endl;
			return ;
		}
		//copy
		ForwardIterator(const ForwardIterator& other) : RandomAccessIterator<T>(other)
		{
			std::cout << "Copy Constructor of FI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~ForwardIterator()
		{
			std::cout << "Destructor of FI called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		ForwardIterator&	operator=(const ForwardIterator& other)
		{
			RandomAccessIterator<T>::operator=(other);
			std::cout << "Assignment Operator of FI called" << std::endl;
			return (*this);

		}

		// --------------------------INCREMENT OPERATORS------------------------
		// prefix increment
		ForwardIterator&	operator++(void)
		{
			RandomAccessIterator<T>::operator++();
			return (*this);
		}
		// postfix increment
		ForwardIterator	operator++(int n)
		{
			RandomAccessIterator<T>::operator++(n);
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void)
		{
			return (RandomAccessIterator::operator->());
		}
		// dereference operator
		reference	operator*(void)
		{
			return (RandomAccessIterator::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(ForwardIterator const& other) const
		{
			return (RandomAccessIterator::operator==(other));
		}
		// != operator, is not equal to
		bool	operator!=(ForwardIterator const& other) const
		{
			return (RandomAccessIterator::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type*	_ptr;
};

#endif
