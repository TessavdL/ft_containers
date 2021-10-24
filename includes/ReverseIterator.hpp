/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ReverseIterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 21:09:41 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/18 16:39:55 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include <iostream>
# include <iterator>

namespace ft {
template <class Iterator>
class reverse_iterator
{
	public:
		typedef Iterator 													iterator_type;
		typedef typename std::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename std::iterator_traits<Iterator>::value_type			value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer			pointer;
		typedef typename std::iterator_traits<Iterator>::reference			reference;

		reverse_iterator(void) : _base()
		{
			// std::cout << "Default constructor of ReverseIterator called" << std::endl;
		}
		explicit reverse_iterator(iterator_type it) : _base(it)
		{
			// std::cout << "Parameter constructor of ReverseIterator called" << std::endl;
		}
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it._base)
		{
			// std::cout << "Copy constructor of ReverseIterator called" << std::endl;
		}

		iterator_type	base(void) const
		{
			return (this->_base);
		}

		reference	operator*(void)
		{
			this->_base--;
			return (*(this->_base));
		}

		pointer	operator->(void)
		{
			return (this->base);
		}

		reference	operator[](difference_type n)
		{
			return (this->base()[-n-1]);
		}

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

		#if iterator_category == random_access_iterator_tag
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

		#endif

	protected:
		iterator_type	_base;
};

	// relational operators
	template<class Iter>
	bool	operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs._base == rhs._base);
	}
	template<class Iter>// != operator, is not equal to
	bool	operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (!(*lhs == rhs));
	}
	template<class Iter>// > operator, greater than
	bool	operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs._base > rhs._base);
	}	
	template<class Iter>// < operator, less than
	bool	operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs._base < rhs._base);
	}	
	template<class Iter>// >= operator, greater than or equal to
	bool	operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (!(lhs < rhs));
	}
	template<class Iter>// <= operator, less than or equal to
	bool	operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class Iter>
	reverse_iterator<Iter>	operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it)
	{
		return (rev_it + n);
	}
	template <class Iter>
	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
	{
		return (lhs._base - rhs._base);
	}
}

#endif
