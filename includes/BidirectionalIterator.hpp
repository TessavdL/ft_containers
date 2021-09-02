/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 15:35:44 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/21 17:07:59 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "./RandomAccessIterator.hpp"

template <class T>
class BidirectionalIterator : public RandomAccessIterator<T>
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
		BidirectionalIterator(void) : RandomAccessIterator<T>()
		{
			std::cout << "Default Constructor of BI called" << std::endl;
			return ;
		}
		// parameter
		BidirectionalIterator(pointer ptr) : RandomAccessIterator<T>(ptr)
		{
			std::cout << "Parameter Constructor of BI called" << std::endl;
			return ;
		}
		// copy
		BidirectionalIterator(const BidirectionalIterator& other) : RandomAccessIterator<T>(other)
		{
			std::cout << "Copy Constructor of BI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~BidirectionalIterator(void)
		{
			std::cout << "Destructor of BI called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		BidirectionalIterator&	operator=(const BidirectionalIterator& other)
		{
			RandomAccessIterator<T>::operator=(other);
			std::cout << "Assignment Operator of BI called" << std::endl;
			return (*this);

		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		// prefix decrement
		BidirectionalIterator&	operator--(void)
		{
			RandomAccessIterator<T>::operator--();
			return (*this);
		}
		// postfix decrement
		BidirectionalIterator	operator--(int n)
		{
			RandomAccessIterator<T>::operator--(n);
			return (*this);
		}
		// prefix increment
		BidirectionalIterator&	operator++(void)
		{
			RandomAccessIterator<T>::operator++();
			return (*this);
		}
		// postfix increment
		BidirectionalIterator	operator++(int n)
		{
			RandomAccessIterator<T>::operator++(n);
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void)
		{
			return (RandomAccessIterator<T>::operator->());
		}
		// dereference operator
		reference	operator*(void)
		{
			return (RandomAccessIterator<T>::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const BidirectionalIterator& other) const
		{
			return (RandomAccessIterator<T>::operator==(other));
		}
		// != operator, is not equal to
		bool	operator!=(const BidirectionalIterator& other) const
		{
			return (RandomAccessIterator<T>::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type*	_ptr;
};

#endif
