/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   InputBinarySearchTreeIterator.hpp                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 15:06:58 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/19 15:46:29 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BINARY_SEARCH_TREE_ITERATOR
# define INPUT_BINARY_SEARCH_TREE_ITERATOR

# include <iostream>

# include "./BinarySearchTreeIterator.hpp"

namespace ft {
template <typename, typename>
class pair;
}

namespace ft {
template <typename>
class node;
}

template <class T = ft::pair<class T1, class T2> >
class InputBinarySearchTreeIterator : public BinarySearchTreeIterator<T>
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T						value_type;
		typedef value_type*				pointer;
		typedef value_type&				reference;
		typedef ft::node<value_type>	node;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		InputBinarySearchTreeIterator(void) : BinarySearchTreeIterator<value_type>()
		{
			// std::cout << "Default constructor IBSTI called" << std::endl;
		}
		InputBinarySearchTreeIterator(node* node, value_type* ptr) : BinarySearchTreeIterator<value_type>(node, ptr)
		{
			// std::cout << "Parameter constructor IBSTI called" << std::endl;
		}
		InputBinarySearchTreeIterator(const InputBinarySearchTreeIterator& other) : BinarySearchTreeIterator<value_type>(other)
		{
			*this = other;
			// std::cout << "Copy constructor of IBSTI called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~InputBinarySearchTreeIterator(void)
		{
			// std::cout << "Destructor of IBSTI called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		InputBinarySearchTreeIterator&	operator=(const InputBinarySearchTreeIterator& other)
		{
			// std::cout << "Assignment operator of IBSTI called" << std::endl;
			if (this != &other)
			{
				this->_node = other._node;
				this->_ptr = other._ptr;
			}
			return (*this);
		}

		// -------------------------INCREMENT OPERATORS-------------------------
		InputBinarySearchTreeIterator&	operator++(void)
		{
			return (BinarySearchTreeIterator<value_type>::operator++());
		}
		InputBinarySearchTreeIterator	operator++(int)
		{
			return (BinarySearchTreeIterator<value_type>::operator++(int));
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void)
		{
			return (BinarySearchTreeIterator<value_type>::operator->());
		}
		reference	operator*(void)
		{
			return (BinarySearchTreeIterator<value_type>::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		bool	operator==(const InputBinarySearchTreeIterator& other) const
		{
			return (BinarySearchTreeIterator<value_type>::operator==(other));
		}
		bool	operator!=(const InputBinarySearchTreeIterator& other) const
		{
			return (!(*this == other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		node*		_node;
		value_type*	_ptr;
}

# endif
