/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/24 13:58:51 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/30 15:59:53 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <memory>
# include <exception>

# include "./IteratorTraits.hpp"
# include "./RandomAccessIterator.hpp"
# include "./ReimplementedFunctions.hpp"
# include "./ReverseIterator.hpp"
# include "./TypeTraits.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef RandomAccessIterator<value_type>			iterator;
		typedef RandomAccessIterator<const value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		explicit vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<ft::has_iterator_member_types<InputIterator>::value, InputIterator>::type* = 0) :
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->assign(first, last);
		}

		vector(const vector& x) :
			_alloc(x._alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->assign(x.begin(), x.end());
		}

		// -----------------------------DESTRUCTOR------------------------------
		~vector(void)
		{
			this->clear();
			this->_deallocate();
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		vector&	operator=(const vector& other)
		{
			if (this != &other)
			{
				this->_alloc = other._alloc;
				this->assign(other.begin(), other.end());
			}
			return (*this);
		}

		// ----------------------------ELEMENT ACCESS---------------------------
		reference	at(size_type pos)
		{
			if (pos >= this->_size)
			{
				throw std::out_of_range("ft::vector::at");
			}
			return (this->_first_element[pos]);
		}

		const_reference	at(size_type pos) const
		{
			if (pos >= this->_size)
			{
				throw std::out_of_range("ft::vector::at");
			}
			return (this->_first_element[pos]);
		}

		reference operator[](size_type pos)
		{
			return (this->_first_element[pos]);
		}

		const_reference operator[](size_type pos) const
		{
			return (this->_first_element[pos]);
		}

		reference	front(void)
		{
			return (this->_first_element[0]);
		}

		const_reference	front(void) const
		{
			return (this->_first_element[0]);
		}

		reference	back(void)
		{
			return (this->_first_element[this->_size - 1]);
		}

		const_reference	back(void) const
		{
			return (this->_first_element[this->_size - 1]);
		}

		pointer	data(void)
		{
			return (this->_first_element);
		}

		const_pointer	data(void) const
		{
			return (this->_first_element);
		}

		// ------------------------------ITERATORS------------------------------
		iterator	begin(void)
		{
			return (iterator(this->_first_element));
		}

		const_iterator	begin(void) const
		{
			return (const_iterator(this->_first_element));
		}

		iterator	end(void)
		{
			return (iterator(this->_first_element + this->_size));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(this->_first_element + this->_size));
		}

		reverse_iterator	rbegin(void)
		{
			return (reverse_iterator(this->_first_element + this->_size));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(this->_first_element + this->_size));
		}

		reverse_iterator	rend(void)
		{
			return (reverse_iterator(this->_first_element));
		}

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(this->_first_element));
		}

		// -------------------------------CAPACITY------------------------------
		bool	empty(void) const
		{
			if (this->_size == 0)
			{
				return (true);
			}
			else
			{
				return (false);
			}
		}

		size_type	size(void) const
		{
			return (this->_size);
		}

		size_type	max_size(void) const
		{
			return (this->_alloc.max_size());
		}

		void	reserve(size_type new_cap)
		{
			if (new_cap > this->max_size())
			{
				throw (std::length_error("ft::vector::reserve"));
			}
			if (new_cap > this->_capacity)
			{
				this->_reallocate(new_cap);
			}
		}

		size_type	capacity(void) const
		{
			return (this->_capacity);
		}

		// ------------------------------MODIFIERS------------------------------
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last, typename ft::enable_if<ft::has_iterator_member_types<InputIterator>::value, InputIterator>::type* = 0)
		{
			typename ft::iterator_traits<InputIterator>::difference_type	n = ft::distance(first, last);
			size_type														new_capacity = static_cast<size_type>(n);

			if (new_capacity > this->max_size())
			{
				throw (std::length_error("cannot create ft::vector larger than max_size()"));
			}
			this->clear();
			if (new_capacity > this->_capacity)
			{
				this->_deallocate();
				this->_first_element = this->_alloc.allocate(new_capacity);
				this->_capacity = new_capacity;
			}
			for (size_type i = 0; first != last; first++, i++)
			{
				this->_alloc.construct(this->_first_element + i, *first);
			}
			this->_size = new_capacity;
		}

		void	assign(size_type n, const value_type& val)
		{
			if (n > this->max_size())
			{
				throw (std::length_error("cannot create ft::vector larger than max_size()"));
			}
			this->clear();
			if (n > this->_capacity)
			{
				this->_deallocate();
				this->_first_element = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(this->_first_element + i, val);
			}
			this->_size = n;
		}

		void	clear(void)
		{
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_alloc.destroy(this->_first_element + i);
			}
			this->_size = 0;
		}

		iterator	insert(iterator pos, const T& value)
		{
			iterator	ret = pos;

			this->insert(pos, 1, value);
			return (ret);
		}

		void	insert(iterator pos, size_type count, const T& value)
		{
			difference_type	n = pos - this->begin();

			if (count + this->_capacity >= this->max_size())
			{
				throw (std::length_error("ft::vector::_fill_insert"));
			}
			if (this->_size == 0)
			{
				return (this->assign(count, value));
			}
			if (this->_size + count > this->_capacity)
			{
				if (this->_capacity * 2 < this->_size + count)
				{
					this->_reallocate(this->_size + count);
				}
				else
				{
					this->_reallocate(this->_capacity * 2);
				}
			}

			difference_type old_end = this->_size - 1;
			difference_type new_end = this->_size - 1 + count;

			this->_size += count;
			for (iterator it = this->end(); it > this->begin() + n + count; it--, old_end--, new_end--)
			{
				this->_alloc.construct(this->_first_element + new_end, *(this->_first_element + old_end));
				this->_alloc.destroy(this->_first_element + old_end);
			}
			for (size_type i = 0; i < count; i++)
			{
				this->_alloc.destroy(this->_first_element + n + i);
				this->_alloc.construct(this->_first_element + n + i, value);
			}
		}

		template<class InputIterator>
		void	insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<ft::has_iterator_member_types<InputIterator>::value, InputIterator>::type* = 0)
		{
			typename ft::iterator_traits<InputIterator>::difference_type	n = ft::distance(this->begin(), pos);
			typename ft::iterator_traits<InputIterator>::difference_type	count = ft::distance(first, last);

			if (count + this->_capacity >= this->max_size())
			{
				throw (std::length_error("ft::vector::_range_insert"));
			}
			if (this->_size == 0)
			{
				return (this->assign(first, last));
			}
			if (this->_size + count > this->_capacity)
			{
				if (this->_capacity * 2 < this->_size + count)
				{
					this->_reallocate(this->_size + count);
				}
				else
				{
					this->_reallocate(this->_capacity * 2);
				}
			}

			difference_type old_end = this->_size - 1;
			difference_type new_end = this->_size - 1 + count;

			this->_size += count;
			for (iterator it = this->end(); it > this->begin() + n + count; it--, old_end--, new_end--)
			{
				this->_alloc.construct(this->_first_element + new_end, *(this->_first_element + old_end));
				this->_alloc.destroy(this->_first_element + old_end);
			}
			for (difference_type i = 0; i < count; i++)
			{
				this->_alloc.destroy(this->_first_element + n + i);
				this->_alloc.construct(this->_first_element + n + i, *first);
				first++;
			}
		}

		iterator	erase(iterator pos)
		{
			iterator		ret = pos;
			difference_type	i = ft::distance(this->begin(), pos);

			this->_size--;
			for (; pos != this->end(); pos++, i++)
			{
				this->_alloc.construct(this->_first_element + i, *(this->_first_element + i + 1));
				this->_alloc.destroy(this->_first_element + i + 1);
			}
			return (ret);
		}

		iterator	erase(iterator first, iterator last)
		{
			iterator		ret = first;
			difference_type	count = ft::distance(first, last);
			difference_type	i = ft::distance(this->begin(), first);

			for (; first != this->end() - count; first++, i++)
			{
				this->_alloc.construct(this->_first_element + i, *(this->_first_element + i + count));
				this->_alloc.destroy(this->_first_element + i + count);
			}
			for (; i < count; i++)
			{
				this->_alloc.destroy(this->_first_element + i);
			}
			this->_size -= count;
			return (ret);
		}

		void	push_back(const T& value)
		{
			if (this->_capacity == this->max_size())
			{
				throw (std::length_error("ft::vector::push_back"));
			}
			if (this->_capacity == 0)
			{
				this->assign(1, value);
			}
			else if (this->_capacity > 0)
			{
				if (this->_size == this->_capacity)
				{
					this->_reallocate(this->_capacity * 2);
				}
				this->_alloc.construct(this->_first_element + this->_size, value);
				this->_size++;
			}
		}

		void	pop_back(void)
		{
			if (this->_size > 0)
			{
				this->_alloc.destroy(this->_first_element + (this->_size - 1));
				this->_size--;
			}
		}

		void	resize(size_type count, T value = T())
		{
			if (count < this->_size)
			{
				for (size_type i = count; i < this->_size; i++)
				{
					this->_alloc.destroy(this->_first_element + i);
				}
				this->_size = count;
			}
			else
			{
				for (size_type i = count - this->_size; i > 0; i--)
				{
					this->push_back(value);
				}
			}
		}

		void	swap(vector<value_type>& other)
		{
			std::swap(this->_alloc, other._alloc);
			std::swap(this->_capacity, other._capacity);
			std::swap(this->_first_element, other._first_element);
			std::swap(this->_size, other._size);
		}

		// ------------------------------ALLOCATOR------------------------------
		allocator_type	get_allocator(void) const
		{
			return (this->_alloc);
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~
		void	_deallocate(void)
		{
			if (this->_capacity > 0)
			{
				this->_alloc.deallocate(this->_first_element, this->_capacity);
				this->_first_element = NULL;
				this->_capacity = 0;
			}
		}

		void	_reallocate(size_type new_capacity)
		{
			value_type*	temp = NULL;

			if (new_capacity > 0)
			{
				temp = this->_alloc.allocate(new_capacity);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(temp + i, *(this->_first_element + i));
					this->_alloc.destroy(this->_first_element + i);
				}
				this->_deallocate();
				this->_first_element = temp;
				this->_capacity = new_capacity;
			}
		}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~
		allocator_type	_alloc;
		size_type		_capacity;
		value_type*		_first_element;
		size_type		_size;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~NON-MEMBER FUCTION OVERLOADS~~~~~~~~~~~~~~~~~~~~~~~
// ----------------------------RELATIONAL OPERATORS-----------------------------
template <typename T, class Allocator >
bool	operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return (false);
	}
	else
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
}

template <typename T, class Allocator >
bool	operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, class Allocator >
bool	operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::less<T>()));
}

template <typename T, class Allocator >
bool	operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::less<T>()));
}

template <typename T, class Allocator  >
bool	operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (!(lhs > rhs));
}

template <typename T, class Allocator >
bool	operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

// ------------------------------------SWAP-------------------------------------
template <class T, class Alloc>
void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	vector<T, Alloc>	temp;

	temp.swap(x);
	x.swap(y);
	y.swap(x);
}

}	// end of namespace ft

#endif
