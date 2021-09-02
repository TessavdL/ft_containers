/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BinarySearchTreeIterator.hpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 11:30:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/26 11:56:08 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later
# include <utility>		// for std::pair, should include own pair later
# include <memory>		// for std::allocator

# include </home/tevan-de/ft_containers/includes/Node.hpp>

template <class Pair = std::pair<class Key, class T>>
class BinarySearchTreeIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef std::pair<class Key, class T>	value_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef std::ptrdiff_t					difference_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		BinarySearchTreeIterator(void) : RandomAccessIterator<value_type>()
		{
			std::cout << "Default Constructor of BI called" << std::endl;
			return ;
		}
		// parameter
		BinarySearchTreeIterator(pointer ptr) : RandomAccessIterator<value_type>(ptr)
		{
			std::cout << "Parameter Constructor of BI called" << std::endl;
			return ;
		}
		// copy
		BinarySearchTreeIterator(const BinarySearchTreeIterator& other) : RandomAccessIterator<value_type>(other)
		{
			std::cout << "Copy Constructor of BI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~BinarySearchTreeIterator(void)
		{
			std::cout << "Destructor of BI called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		BinarySearchTreeIterator&	operator=(const BinarySearchTreeIterator& other)
		{
			RandomAccessIterator<value_type>::operator=(other);
			std::cout << "Assignment Operator of BI called" << std::endl;
			return (*this);

		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		// prefix decrement
		BinarySearchTreeIterator&	operator--(void)
		{
			RandomAccessIterator<value_type>::operator--();
			return (*this);
		}
		// postfix decrement
		BinarySearchTreeIterator	operator--(int n)
		{
			RandomAccessIterator<value_type>::operator--(n);
			return (*this);
		}
		// prefix increment
		BinarySearchTreeIterator&	operator++(void)
		{
			RandomAccessIterator<value_type>::operator++();
			return (*this);
		}
		// postfix increment
		BinarySearchTreeIterator	operator++(int n)
		{
			RandomAccessIterator<value_type>::operator++(n);
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void)
		{
			return (RandomAccessIterator<value_type>::operator->());
		}
		// dereference operator
		reference	operator*(void)
		{
			return (RandomAccessIterator<value_type>::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const BinarySearchTreeIterator& other) const
		{
			return (RandomAccessIterator<value_type>::operator==(other));
		}
		// != operator, is not equal to
		bool	operator!=(const BinarySearchTreeIterator& other) const
		{
			return (RandomAccessIterator<value_type>::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type*	_ptr;
};

#endif
