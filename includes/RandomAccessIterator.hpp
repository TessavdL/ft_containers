/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/26 21:51:11 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 14:02:58 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "./IteratorTraits.hpp"

template <class T>
class RandomAccessIterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T										value_type;
		typedef value_type*								pointer;
		typedef value_type&								reference;
		typedef std::ptrdiff_t							difference_type;
		typedef ft::random_access_iterator_tag			iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		RandomAccessIterator(void) :
			_ptr(NULL) {}

		RandomAccessIterator(pointer ptr) :
			_ptr(ptr) {}

		RandomAccessIterator(const RandomAccessIterator& other) :
			_ptr(other._ptr) {}

		template <typename Iter>
		RandomAccessIterator(const RandomAccessIterator<Iter> other) :
			_ptr(other.operator->()) {}

		// -----------------------------DESTRUCTOR------------------------------
		~RandomAccessIterator(void) {}

		// ------------------------ASSIGNMENT OPERATORS-------------------------
		RandomAccessIterator&	operator=(const RandomAccessIterator& other)
		{
			if (this != &other)
			{
				this->_ptr = other._ptr;
			}
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
			RandomAccessIterator&	it(*this);

			it._ptr += n;
			return (it);
		}

		RandomAccessIterator&	operator-(difference_type n)
		{
			RandomAccessIterator&	it(*this);

			it._ptr -= n;
			return (it);
		}

		difference_type	operator-(const RandomAccessIterator& other)
		{
			difference_type	n;

			n = this->_ptr - other._ptr;
			return (n);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		RandomAccessIterator&	operator--(void)
		{
			this->_ptr--;
			return (*this);
		}

		RandomAccessIterator	operator--(int)
		{
			RandomAccessIterator	it = *this;

			--(*this);
			return (it);
		}

		RandomAccessIterator&	operator++(void)
		{
			this->_ptr++;
			return (*this);
		}

		RandomAccessIterator	operator++(int)
		{
			RandomAccessIterator	it = *this;

			++(*this);
			return (it);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void) const
		{
			return (&(*this->_ptr));
		}

		reference	operator*(void) const
		{
			return (*(this->_ptr));
		}

		reference	operator[](int index) const
		{
			return (*(this->_ptr + index));
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		bool	operator==(const RandomAccessIterator& other) const
		{
			return (this->_ptr == other._ptr);
		}

		bool	operator!=(const RandomAccessIterator& other) const
		{
			return (!(*this == other));
		}

		bool	operator>(const RandomAccessIterator& other) const
		{
			return (this->_ptr > other._ptr);
		}

		bool	operator<(const RandomAccessIterator& other) const
		{
			return (this->_ptr < other._ptr);
		}

		bool	operator>=(const RandomAccessIterator& other) const
		{
			return (!(this->_ptr < other._ptr));
		}

		bool	operator<=(const RandomAccessIterator& other) const
		{
			return (!(this->_ptr > other._ptr));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~~~
		pointer	_ptr;
};

# endif
