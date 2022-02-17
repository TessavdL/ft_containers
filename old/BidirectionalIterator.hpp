/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 15:35:44 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/25 15:02:13 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>

# include "./IteratorTraits.hpp"

template <class T>
class BidirectionalIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T								value_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef std::ptrdiff_t					difference_type;
		typedef ft::bidrectional_iterator_tag	iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		BidirectionalIterator(void) : _ptr(NULL)
		{
			// std::cout << "Default Constructor of BI called" << std::endl;
		}
		BidirectionalIterator(pointer ptr) _ptr(ptr)
		{
			// std::cout << "Parameter Constructor of BI called" << std::endl;
		}
		BidirectionalIterator(const BidirectionalIterator& other)
		{
			*this = other;
			// std::cout << "Copy Constructor of BI called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~BidirectionalIterator(void)
		{
			// std::cout << "Destructor of BI called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		BidirectionalIterator&	operator=(const BidirectionalIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
			}
			// std::cout << "Assignment Operator of BI called" << std::endl;
			return (*this);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		BidirectionalIterator&	operator--(void)
		{
			this->_ptr--;
			return (*this);
		}
		BidirectionalIterator	operator--(int)
		{
			BidirectionalIterator	it = *this;

			--(*this);
			return (it);
		}
		BidirectionalIterator&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}
		BidirectionalIterator	operator++(int)
		{
			BidirectionalIterator	it = *this;

			++(*this);
			return (it);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void)
		{
			return (this->_ptr);
		}
		reference	operator*(void)
		{
			return (*(this->_ptr));
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		bool	operator==(const BidirectionalIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}
		bool	operator!=(const BidirectionalIterator& other) const
		{
			return (!(*this == other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer	_ptr;
};

#endif
