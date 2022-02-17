/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BinarySearchTreeIterator.hpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 11:30:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 14:03:22 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include "IteratorTraits.hpp"
# include "Node.hpp"

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
		BinarySearchTreeIterator(void) :
			_ptr(NULL), _node(NULL) {}

		BinarySearchTreeIterator(pointer val, node* n) :
			_ptr(val), _node(n) {}

		BinarySearchTreeIterator(const BinarySearchTreeIterator& other) :
			_ptr(other._ptr), _node(other._node) {}

		template <class T1, class U1>
		BinarySearchTreeIterator(const BinarySearchTreeIterator<T1, U1>& other) :
			_ptr(other.operator->()), _node(other.get_node()) {}

		// -----------------------------DESTRUCTOR------------------------------
		~BinarySearchTreeIterator(void) {}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		BinarySearchTreeIterator&	operator=(const BinarySearchTreeIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
				this->_node = other._node;
			}
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
			BinarySearchTreeIterator	it = (*this);

			this->_node = this->_node->previous();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (it);
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
			BinarySearchTreeIterator	it = (*this);

			this->_node = this->_node->next();
			if (this->_node == NULL)
			{
				this->_ptr = NULL;
			}
			else
			{
				this->_ptr = this->_node->data;
			}
			return (it);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void) const
		{
			return (this->_ptr);
		}

		reference	operator*(void) const
		{
			return (*this->_ptr);
		}

		// ------------------------MEMBER ACCESS FUNCTION-----------------------
		node*	get_node(void) const
		{
			return (this->_node);
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
