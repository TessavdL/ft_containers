/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/26 21:51:11 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/21 17:11:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>

// Random Access Iterator (RAI) is the most complete iterator in terms of functionality
// RAI allows reading, incrementing (with/without multiple passes), decrementing and random access
// https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
// https://internalpointers.com/post/writing-custom-iterators-modern-cpp

template <class T>
class RandomAccessIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;
		typedef std::ptrdiff_t	difference_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		RandomAccessIterator(void) : _ptr(nullptr)
		{
			// std::cout << "Default Constructor of RAI called" << std::endl;
			return ;
		}
		// parameter
		RandomAccessIterator(pointer ptr) : _ptr(ptr)
		{
			// std::cout << "Parameter Constructor of RAI called" << std::endl;
			return ;
		}
		// copy
		RandomAccessIterator(const RandomAccessIterator& other) : _ptr(other._ptr)
		{
			// std::cout << "Copy Constructor of RAI called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		virtual ~RandomAccessIterator(void)
		{
			// std::cout << "Destructor of RAI called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATORS-------------------------
		RandomAccessIterator&	operator=(const RandomAccessIterator& other)
		{
			if (this != &other)
				this->_ptr = other._ptr;
			// std::cout << "Assignment Operator of RAI called" << std::endl;
			return (*this);
		}
		RandomAccessIterator&	operator+=(const difference_type& n)
		{
			difference_type	m;

			m = n;
			if (n > 0)
			{
				while (m > 0)
				{
					++(*this);
					m--;
				}
			}
			else if (n < 0)
			{
				while (m < 0)
				{
					--(*this);
					m++;
				}
			}
			return (*this);
		}
		RandomAccessIterator&	operator-=(difference_type n)
		{
			return (*this += -n);
		}
		RandomAccessIterator&	operator+(difference_type n)
		{
			RandomAccessIterator	it = *this;

			return (it += n);
		}
		RandomAccessIterator&	operator-(difference_type n)
		{
			RandomAccessIterator	it = *this;

			return (it -= n);
		}
		difference_type	operator-(const RandomAccessIterator& other)
		{
			difference_type	n;

			n = this->_ptr - other._ptr;
			return (n);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		// article about prefix and postfix increments https://hownot2code.com/2016/06/30/use-a-prefix-increment-operator-i-in-iterators-instead-of-a-postfix-i-operator/
		// prefix decrement
		RandomAccessIterator&	operator--(void)
		{
			this->_ptr--;
			return (*this);
		}
		// postfix decrement
		RandomAccessIterator	operator--(int n)
		{
			RandomAccessIterator	it = *this;

			--(*this);
			return (it);
		}
		// prefix increment
		RandomAccessIterator&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}
		// postfix increment
		RandomAccessIterator	operator++(int n)
		{
			RandomAccessIterator	it = *this;

			++(*this);
			return (it);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		// returns a pointer to the current position of the iterator
		pointer	operator->(void)
		{
			return (this->_ptr);
		}
		// dereference operator
		// returns a reference so the type is of l-value
		// returns a reference of the value at the current position of the iterator
		reference	operator*(void)
		{
			return (*(this->_ptr));
		}
		// subscript operator
		// has a high precedence
		// returns a reference so the type is of l-value
		// returns a reference of the value at the index of the iterator
		reference	operator[](int index)
		{
			return (*(this->_ptr + index));
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const RandomAccessIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}
		// != operator, is not equal to
		bool	operator!=(const RandomAccessIterator& other) const
		{
			return (!(*this == other));
		}
		// > operator, greater than
		bool	operator>(const RandomAccessIterator& other) const
		{
			return (this->_ptr > other._ptr);
		}	
		// < operator, less than
		bool	operator<(const RandomAccessIterator& other) const
		{
			return (this->_ptr < other._ptr);
		}	
		// >= operator, greater than or equal to
		bool	operator>=(const RandomAccessIterator& other) const
		{
			return (!(this->_ptr < other._ptr));
		}
		// <= operator, less than or equal to
		bool	operator<=(const RandomAccessIterator& other) const
		{
			return (!(this->_ptr > other._ptr));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type*	_ptr;
};

# endif
