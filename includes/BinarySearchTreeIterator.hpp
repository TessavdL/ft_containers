/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BinarySearchTreeIterator.hpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 11:30:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/29 15:37:40 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include <iostream>	// for output, prob remove later

# include "IteratorTraits.hpp"
# include "Node.hpp"
# include "ReimplementedFunctions.hpp" // redundant?

namespace ft {
template<typename>
class node;
}

template <class T, class U>
class BinarySearchTreeIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T								value_type;
		typedef U								node;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef std::ptrdiff_t					difference_type;
		typedef ft::bidirectional_iterator_tag	iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		BinarySearchTreeIterator(void) : _ptr(NULL), _node(NULL)
		{
			// std::cout << "Default Constructor of BSTI called" << std::endl;
		}
		BinarySearchTreeIterator(pointer val, node* n) : _ptr(val), _node(n)
		{
			// std::cout << "Parameter Constructor of BSTI called" << std::endl;
		}
		BinarySearchTreeIterator(const BinarySearchTreeIterator& other)
		{
			*this = other;
			// std::cout << "Copy Constructor of BSTI called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~BinarySearchTreeIterator(void)
		{
			// std::cout << "Destructor of BSTI called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		BinarySearchTreeIterator&	operator=(const BinarySearchTreeIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
				this->_node = other._node;
			}
			// std::cout << "Assignment Operator of BSTI called" << std::endl;
			return (*this);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		BinarySearchTreeIterator&	operator--(void)
		{
			this->_node = this->_node->previous();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (*this);
		}
		BinarySearchTreeIterator	operator--(int)
		{
			BinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->previous();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (bsti);
		}
		BinarySearchTreeIterator&	operator++(void)
		{
			this->_node = this->_node->next();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (*this);
		}
		BinarySearchTreeIterator	operator++(int)
		{
			BinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->next();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (bsti);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void)
		{
			return (this->_ptr);
		}
		reference	operator*(void)
		{
			return (*this->_ptr);
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		bool	operator==(const BinarySearchTreeIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}
		bool	operator!=(const BinarySearchTreeIterator& other) const
		{
			return (!(*this == other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer	_ptr;
		node*	_node;
};

#endif
