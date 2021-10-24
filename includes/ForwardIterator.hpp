/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ForwardIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:51:07 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/24 18:25:51 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARD_ITERATOR_HPP
# define FORWARD_ITERATOR_HPP

# include <iostream>

# include "./IteratorTraits.hpp"

template <class T>
class ForwardIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T							value_type;
		typedef value_type*					pointer;
		typedef value_type&					reference;
		typedef std::ptrdiff_t				difference_type;
		typedef ft::forward_iterator_tag	iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		ForwardIterator() : _ptr(nullptr)
		{
			// std::cout << "Default Constructor of FI called" << std::endl;
		}
		ForwardIterator(pointer ptr) : _ptr(ptr)
		{
			// std::cout << "Parameter Constructor of FI called" << std::endl;
		}
		ForwardIterator(const ForwardIterator& other)
		{
			*this = other;
			// std::cout << "Copy Constructor of FI called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~ForwardIterator()
		{
			// std::cout << "Destructor of FI called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		ForwardIterator&	operator=(const ForwardIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
			}
			// std::cout << "Assignment Operator of FI called" << std::endl;
			return (*this);
		}

		// --------------------------INCREMENT OPERATORS------------------------
		ForwardIterator&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}
		ForwardIterator	operator++(int)
		{
			ForwardIterator	it = *this;

			++(*this);
			return (it);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void)
		{
			return (RandomAccessIterator::operator->());
		}
		reference	operator*(void)
		{
			return (RandomAccessIterator::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		bool	operator==(ForwardIterator const& other) const
		{
			return (RandomAccessIterator::operator==(other));
		}
		bool	operator!=(ForwardIterator const& other) const
		{
			return (RandomAccessIterator::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer	_ptr;
};

#endif
