/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   InputIterator.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:52:57 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/24 18:26:02 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include <iostream>

# include "./IteratorTraits.hpp"

template <class T>
class InputIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T						value_type;
		typedef value_type*				pointer;
		typedef value_type&				reference;
		typedef std::ptrdiff_t			difference_type;
		typedef ft::input_iterator_tag	iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		InputIterator(pointer ptr) : _ptr(ptr)
		{
			// std::cout << "Parameter Constructor of II called" << std::endl;
		}
		InputIterator(const InputIterator& other)
		{
			*this = other;
			// std::cout << "Copy Constructor of II called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~InputIterator(void)
		{
			// std::cout << "Destructor of II called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		InputIterator&	operator=(const InputIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
			}
			// std::cout << "Assignment Operator of II called" << std::endl;
			return (*this);
		}

		// --------------------------INCREMENT OPERATORS------------------------
		InputIterator&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}
		InputIterator	operator++(int)
		{
			InputIterator	it = *this;

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
		bool	operator==(const InputIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}
		bool	operator!=(const InputIterator& other) const
		{
			return (!(*this == other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer	_ptr;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~
		InputIterator(void) : _ptr(nullptr)
		{
			// std::cout << "Default Constructor of II called" << std::endl;
		}
};

#endif
