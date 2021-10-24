/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseBinarySearchTreeIterator.hpp                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 18:02:23 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/20 11:52:51 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_BINARY_SEARCH_TREE_ITERATOR_HPP
# define REVERSE_BINARY_SEARCH_TREE_ITERATOR_HPP

# include <functional>
# include <iostream>

# include "./BinarySearchTreeIterator.hpp"
# include "./Node.hpp"
# include "./Pair.hpp"

namespace ft {
template<typename, typename>
class pair;
}

namespace ft {
template<typename>
class node;
}

template <class T = ft::node<ft::pair<class T1, class T2> > >
class ReverseBinarySearchTreeIterator : public BinarySearchTreeIterator<T>
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;
		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		ReverseBinarySearchTreeIterator(void) : BinarySearchTreeIterator<T>()
		{
			// std::cout << "Default Constructor of RBSTI called" << std::endl;
			return ;
		}
		// parameter
		ReverseBinarySearchTreeIterator(pointer val, ft::node<value_type>* n) : BinarySearchTreeIterator<T>(val, n)
		{
			std::cout << this->_ptr->first << std::endl;
			std::cout << "Parameter Constructor of RBSTI called" << std::endl;
			return ;
		}
		// copy
		ReverseBinarySearchTreeIterator(const ReverseBinarySearchTreeIterator& other) : BinarySearchTreeIterator<T>(other)
		{
			// std::cout << "Copy Constructor of RBSTI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~ReverseBinarySearchTreeIterator(void)
		{
			// std::cout << "Destructor of RBSTI called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		ReverseBinarySearchTreeIterator&	operator=(const ReverseBinarySearchTreeIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
				this->_node = other._node;
			}
			// std::cout << "Assignment Operator of RBSTI called" << std::endl;
			return (*this);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		// prefix decrement
		ReverseBinarySearchTreeIterator&	operator--(void)
		{
			this->_node = this->_node->next();
			this->_ptr = this->_node->data;
			return (*this);
		}
		// postfix decrement
		ReverseBinarySearchTreeIterator	operator--(int)
		{
			ReverseBinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->next();
			this->_ptr = this->_node->data;
			if (this->_ptr == nullptr)
				std::cout << "this is end" << std::endl;
			return (bsti);
		}
		// prefix increment
		ReverseBinarySearchTreeIterator&	operator++(void)
		{
			this->_node = this->_node->previous();
			this->_ptr = this->node->data;
		}
		// postfix increment
		ReverseBinarySearchTreeIterator	operator++(int)
		{
			ReverseBinarySearchTreeIterator	bsti = (*this);

			this->_node = this->_node->previous();
			this->_ptr = this->_node->data;
			return (bsti);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void) const
		{
			return (this->_node->data);
		}
		// dereference operator
		reference	operator*(void) const
		{
			return (*this->_node->data);
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const ReverseBinarySearchTreeIterator& other) const
		{
			return (BinarySearchTreeIterator<T>::operator==(other));
		}
		// != operator, is not equal to
		bool	operator!=(const ReverseBinarySearchTreeIterator& other) const
		{
			return (BinarySearchTreeIterator<T>::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer					_ptr;
		ft::node<value_type>*	_node;

};

#endif
