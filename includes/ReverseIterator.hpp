/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 21:09:41 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/24 18:24:53 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include <iostream>

# include "./IteratorTraits.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Iterator 													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		reverse_iterator(void) : _base()
		{
			// std::cout << "Default constructor of RI called" << std::endl;
		}
		explicit reverse_iterator(iterator_type it) : _base(it)
		{
			// std::cout << "Parameter constructor of RI called" << std::endl;
		}
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it._base)
		{
			// std::cout << "Copy constructor of RI called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~reverse_iterator(void)
		{
			//std::cout << "Destructor of RI called" << std::endl;
		}

		// ------------------------ASSIGNMENT OPERATORS-------------------------
		reverse_iterator&	operator=(const reverse_iterator& other)
		{
			if (this != &other)
			{
				this->_base = other._base;
			}
			// std::cout << "Assignment Operator of RI called" << std::endl;
			return (*this);
		}
		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(this->_base - n));
		}
		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(this->_base + n));
		}
		reverse_iterator&	operator+=(difference_type n)
		{
			return (*(this->_base -= n));
		}
		reverse_iterator&	operator-=(difference_type n)
		{
			return (*(this->_base += n));
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------	
		iterator_type	base(void) const
		{
			return (this->_base);
		}
		reference	operator*(void)
		{
			iterator_type		temp = this->_base;

			return (*--temp);
		}
		pointer	operator->(void)
		{
			return (&(this->operator*()));
		}
		reference	operator[](difference_type n)
		{
			return (this->base()[-n-1]);
		}

		// -------------------DECREMENT AND INCREMENT OPERATORS-----------------
		reverse_iterator&	operator++(void)
		{
			this->_base--;
			return (*this);
		}
		reverse_iterator	operator++(int)
		{
			reverse_iterator temp = *this;

			++(*this);
			return temp;
		}
		reverse_iterator	operator--(void)
		{
			this->_base++;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;

			--(*this);
			return temp;
		}

	protected:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PROTECTED MEMBER OBJECT~~~~~~~~~~~~~~~~~~~~~~~~~
		iterator_type	_base;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~NON-MEMBER FUCTION OVERLOADS~~~~~~~~~~~~~~~~~~~~~~~
// ----------------------------RELATIONAL OPERATORS-----------------------------
template<class Iter>
bool	operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() == rhs.base());
}
template<class Iter>
bool	operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (!(lhs == rhs));
}
template<class Iter>
bool	operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() > rhs.base());
}	
template<class Iter>
bool	operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() < rhs.base());
}	
template<class Iter>
bool	operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (!(lhs < rhs));
}
template<class Iter>
bool	operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (!(lhs > rhs));
}

// ------------------------------ADDITION OPERATOR------------------------------
template <class Iter>
reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it)
{
	return (rev_it + n);
}

// ----------------------------SUBSTRACTION OPERATOR----------------------------
template <class Iter>
typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{
	return (lhs.base() - rhs.base());
}
}

#endif
