/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BinarySearchTreeIterator.hpp                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 11:30:29 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/15 18:35:09 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
# define BINARY_SEARCH_TREE_ITERATOR_HPP

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later

# include "./Pair.hpp"
# include "./Node.hpp"

namespace ft {
template<typename, typename>
class pair;
}

namespace ft {
template<typename>
class node;
}

template <class T = ft::node<ft::pair<class T1, class T2> > >
class BinarySearchTreeIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T			value_type;
		typedef value_type*	pointer;
		typedef value_type&	reference;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		BinarySearchTreeIterator(void) : _ptr(nullptr), _node(nullptr)
		{
			// std::cout << "Default Constructor of BSTI called" << std::endl;
			return ;
		}
		// parameter
		BinarySearchTreeIterator(pointer val, ft::node<value_type>* n) : _ptr(val), _node(n)
		{
			// std::cout << "Parameter Constructor of BSTI called" << std::endl;
			return ;
		}
		// copy
		BinarySearchTreeIterator(const BinarySearchTreeIterator& other)
		{
			*this = other;
			// std::cout << "Copy Constructor of BSTI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		virtual ~BinarySearchTreeIterator(void)
		{
			// std::cout << "Destructor of BSTI called" << std::endl;
			return ;
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
		// prefix decrement
		BinarySearchTreeIterator&	operator--(void)
		{
			this->_node = this->_node->previous();
			this->_ptr = this->node->data;
			return (*this);
		}
		// postfix decrement
		BinarySearchTreeIterator	operator--(int)
		{
			BinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->previous();
			this->_ptr = this->_node->data;
			return (bsti);
		}
		// prefix increment
		BinarySearchTreeIterator&	operator++(void)
		{
			this->_node = this->_node->next();
			this->_ptr = this->_node->data;
			return (*this);
		}
		// postfix increment
		BinarySearchTreeIterator	operator++(int)
		{
			BinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->next();
			this->_ptr = this->_node->data;
			if (this->_ptr == nullptr)
				std::cout << "this is end" << std::endl;
			return (bsti);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void) const
		{
			return (this->_ptr);
		}
		// dereference operator
		reference	operator*(void) const
		{
			return (*this->_ptr);
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const BinarySearchTreeIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}
		// != operator, is not equal to
		bool	operator!=(const BinarySearchTreeIterator& other) const
		{
			return (!(*this == other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer					_ptr;
		ft::node<value_type>*	_node;

};

#endif
