// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   BinarySearchTreeIterator.hpp                       :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2021/08/26 11:30:29 by tevan-de      #+#    #+#                 */
// /*   Updated: 2021/10/11 12:52:07 by tevan-de      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
// # define BINARY_SEARCH_TREE_ITERATOR_HPP

// # include <functional>	// for std::less, should include own compare later
// # include <iostream>	// for output, prob remove later
// # include <utility>		// for std::pair, should include own pair later
// # include <memory>		// for std::allocator

// # include "../temp.hpp"
// # include "./RandomAccessIterator.hpp"

// template <class T>
// class BinarySearchTreeIterator : public RandomAccessIterator<T>
// {
// 	public:
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 		typedef T					value_type;
// 		typedef value_type*			pointer;
// 		typedef value_type&			reference;
// 		typedef std::ptrdiff_t		difference_type;

// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
// 		// ----------------------------CONSTRUCTORS-----------------------------
// 		// default
// 		BinarySearchTreeIterator(void) : RandomAccessIterator<value_type>()
// 		{
// 			std::cout << "Default Constructor of BSTI called" << std::endl;
// 			return ;
// 		}
// 		// parameter
// 		BinarySearchTreeIterator(pointer ptr) : RandomAccessIterator<T>(ptr)
// 		{
// 			std::cout << "Parameter Constructor of BSTI called" << std::endl;
// 			return ;
// 		}
// 		// copy
// 		BinarySearchTreeIterator(const BinarySearchTreeIterator& other) : RandomAccessIterator<value_type>(other)
// 		{
// 			std::cout << "Copy Constructor of BSTI called" << std::endl;
// 			return ;
// 		}

// 		// -----------------------------DESTRUCTOR------------------------------
// 		~BinarySearchTreeIterator(void)
// 		{
// 			std::cout << "Destructor of BSTI called" << std::endl;
// 			return ;
// 		}

// 		// ------------------------ASSIGNMENT OPERATOR--------------------------
// 		BinarySearchTreeIterator&	operator=(const BinarySearchTreeIterator& other)
// 		{
// 			RandomAccessIterator<value_type>::operator=(other);
// 			std::cout << "Assignment Operator of BSTI called" << std::endl;
// 			return (*this);

// 		}

// 		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
// 		// prefix decrement
// 		BinarySearchTreeIterator&	operator--(void)
// 		{
// 			this->_ptr = this->_ptr->previous();
// 			return (*this);
// 		}
// 		// postfix decrement
// 		BinarySearchTreeIterator	operator--(int n)
// 		{
// 			BinarySearchTreeIterator	bsti = (*this);

// 			this->_ptr = this->_ptr->previous();
// 			return (bsti);
// 		}
// 		// prefix increment
// 		BinarySearchTreeIterator&	operator++(void)
// 		{
// 			std::cout << "here " << std::endl;
// 			value_type*	temp = this->_ptr->next();
// 			this->_ptr = temp;

// 			return (*this);
// 		}
// 		// postfix increment
// 		BinarySearchTreeIterator	operator++(int n)
// 		{
// 			BinarySearchTreeIterator	bsti = (*this);
// 			std::cout << "here2 " << std::endl;
	
// 			this->_ptr = this->_ptr->next(this->_ptr);
// 			return (bsti);
// 		}

// 		// ------------------------MEMBER ACCESS OPERATORS----------------------
// 		// arrow operator
// 		pointer	operator->(void)
// 		{
// 			return (RandomAccessIterator<value_type>::operator->());
// 		}
// 		// dereference operator
// 		reference	operator*(void)
// 		{
// 			return (RandomAccessIterator<value_type>::operator*());
// 		}

// 		// -------------------------RELATIONAL OPERATORS------------------------
// 		// == operator, is equal to
// 		bool	operator==(const BinarySearchTreeIterator& other) const
// 		{
// 			return (RandomAccessIterator<value_type>::operator==(other));
// 		}
// 		// != operator, is not equal to
// 		bool	operator!=(const BinarySearchTreeIterator& other) const
// 		{
// 			return (RandomAccessIterator<value_type>::operator!=(other));
// 		}

// 	private:
// 	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 		value_type*	_ptr;

// };

// #endif
