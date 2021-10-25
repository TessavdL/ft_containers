/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/24 13:58:51 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/25 16:27:36 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>	// for std::swap
# include <cstddef>		// for size_t and ptrdiff_t
# include <iostream>	// for output
# include <memory>		// for std::allocator
# include <exception>	// for out of range exception

# include "./RandomAccessIterator.hpp"
# include "./InputIterator.hpp"
# include "./ReverseIterator.hpp"
# include "./ReimplementedFunctions.hpp"

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T											value_type;
		typedef Allocator									allocator_type;
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
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			// std::cout << "Default construtor is called" << std::endl;
		}
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->_allocate_new(n, val);
			// std::cout << "Fill construtor is called" << std::endl;
		}
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->_allocate_new(first, last);
			// std::cout << "Range construct is called" << std::endl;
		}
		vector(const vector& x) :
			_alloc(x._alloc), _capacity(0), _first_element(NULL), _size(0)
		{
			this->_allocate_new(x.begin(), x.end());
			// std::cout << "Copy construtor is called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~vector(void)
		{
			if (this->_size > 0)
			{
				this->clear();
			}
			if (this->_capacity > 0)
			{
				this->_deallocate();
			}
			// std::cout << "Destructor is called" << std::endl;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		vector&	operator=(vector const& other)
		{
			if (this != &other)
			{
				this->assign(other.begin(), other.end());
			}
			return (*this);
		}

		// ----------------------------ELEMENT ACCESS---------------------------
		reference	at(size_type pos)
		{
			if (pos >= this->_size)
			{
				throw std::out_of_range("ft::vector::at(size_type pos) out of range");
			}
			return (this->_first_element[pos]);
		}
		const_reference	at(size_type pos) const
		{
			if (pos >= this->_size)
			{
				throw std::out_of_range("ft::vector::at(size_type pos) out of range");
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
			if (new_cap > this->_capacity)
			{
				if (this->_capacity == 0)
				{
					this->_first_element = this->_alloc.allocate(new_cap);
					this->_capacity = new_cap;
				}
				else if (this->_capacity > 0)
				{
					this->_reallocate(new_cap);
				}
			}
		}
		size_type	capacity(void) const
		{
			return (this->_capacity);
		}

		// ------------------------------MODIFIERS------------------------------
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			difference_type	n = ft::distance(first, last);
			size_t			i;
			
			this->clear();
			if (n > this->_capacity)
			{
				this->_deallocate();
				this->_first_element = this->_alloc.allocate(n);
				this->_capacity = n;
			}
			for (size_type i = 0; first != last; first++, i++)
			{
				this->_alloc.construct(this->_first_element + i, *first);
			}
			this->_size = n;
		}
		void assign (size_type n, const value_type& val)
		{
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
		// insert
		// if capacity == 0 but pos != begin -> segfault
		iterator insert(iterator pos, const T& value)
		{
			difference_type	n = pos - this->begin();

			std::cout << "n = " << n << " val = " << value << std::endl;

			// allocate space for one and construct the value - if the capacity is zero
			if (this->_capacity == 0)
			{
				this->_allocate_new(1, value);
				return (this->begin());
			}
			// reallocate space - if the container is not empty and the container is full (aka size == capacity)
			if (this->_size == this->_capacity)
			{
				this->_reallocate(this->_capacity * 2);
			}

			difference_type old_end = this->_size - 1;
			difference_type new_end = this->_size - 1 + 1;

			for (iterator it = this->end(); it > this->begin() + n; it--, old_end--, new_end--)
			{
				this->_alloc.construct(this->_first_element + new_end, *(this->_first_element + old_end));
				this->_alloc.destroy(this->_first_element + old_end);
			}
			this->_alloc.destroy(this->_first_element + n);
			this->_alloc.construct(this->_first_element + n, value);
			this->_size++;
			return (pos);
		}
		void	insert(iterator pos, size_type count, const T& value)
		{
			difference_type	n = pos - this->begin();
		
			// allocate space for count and construct the values - if the capacity is zero
			if (this->_capacity == 0)
			{
				this->_allocate_new(count, value);
				return ;
			}
			// reallocate space - if the container is not empty and is or will be full after insert (aka size + count > capacity)
			if (this->_size + count > this->_capacity)
			{
				this->_reallocate(this->_capacity * 2);
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
		template<class InputIt>
		void	insert(iterator pos, InputIt first, InputIt last)
		{
			difference_type	n = pos - this->begin();
			difference_type	count = 0;
			InputIt temp = first;

			while (temp != last)
			{
				count++;
				temp++;
			}
			if (this->_capacity == 0)
			{
				this->_allocate_new(count, *first);
				return ;
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
				this->_alloc.construct(this->_first_element + n + i, *first);
				first++;
			}
		}
		iterator	erase(iterator pos)
		{
			return (this->erase(pos, pos + 1));
		}
		iterator	erase(iterator first, iterator last)
		{
			difference_type	i_first	= first - this->begin();
			difference_type	i_last = last - this->begin();
			difference_type	n = last - first;

			for (iterator it = last; it != this->end(); it++, i_first++, i_last++)
			{
				this->_alloc.destroy(this->_first_element + i_first);
				this->_alloc.construct(this->_first_element + i_first, *(this->_first_element +i_last));
			}
			for (difference_type i = 0; i < n; i++, i_first++)
			{
				this->_alloc.destroy(this->_first_element + i_first);
			}
			this->_size -= n;
			return (this->begin() + i_first);
		}
		void	push_back(const T& value)
		{
			if (this->_capacity == 0)
			{
				this->_allocate_new(1, value);
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
			if (count == 0)
			{
				this->clear();
				this->_deallocate();
			}
			
			if (count < this->_capacity)
			{
				for (size_type i = count; i < this->_size; i++)
				{
					this->_alloc.destroy(this->_first_element + i);
				}
				this->_size = count;
			}
			else if (count > this->_capacity)
			{
				if (this->_capacity == 0)
				{
					this->_allocate_new(count, value);
				}
				else if (this->_capacity > 0)
				{
					if (count > this->_capacity * 2)
					{
						this->_reallocate(count);
					}
					else
					{
						this->_reallocate(this->_capacity * 2);
					}
					for (size_type i = this->_size; i < count; i++)
					{
						this->_alloc.construct(this->_first_element + i, value);
					}
					this->_size = count;
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
		void	_allocate_new(const_iterator first, const_iterator last)
		{
			difference_type	new_capacity = ft::distance(first, last);
			
			if (new_capacity > 0)
			{
				this->_first_element = this->_alloc.allocate(new_capacity);
				this->_capacity = new_capacity;
				for (size_type i = 0; first != last; first++, i++)
				{
					this->_alloc.construct(this->_first_element + i, *first);
				}
				this->_size = new_capacity;
			}
		}

		void	_allocate_new(iterator first, iterator last)
		{
			difference_type	new_capacity = ft::distance(first, last);
			
			if (new_capacity > 0)
			{
				this->_first_element = this->_alloc.allocate(new_capacity);
				this->_capacity = new_capacity;
				for (size_type i = 0; first != last; first++, i++)
				{
					this->_alloc.construct(this->_first_element + i, *first);
				}
				this->_size = new_capacity;
			}
		}

		void	_allocate_new(size_type new_capacity, const T& value)
		{
			if (new_capacity > 0)
			{
				this->_first_element = this->_alloc.allocate(new_capacity);
				for (size_type i = 0; i < new_capacity; i++)
				{
					this->_alloc.construct(this->_first_element + i, value);
				}
				this->_capacity = new_capacity;
				this->_size = new_capacity;
			}
		}

		void	_deallocate(void)
		{
			this->_alloc.deallocate(this->_first_element, this->_capacity);
			this->_first_element = NULL;
			this->_capacity = 0;
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
		return (false);
	return (true);
}

template <typename T, class Allocator >
bool	operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, class Allocator >
bool	operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator >
bool	operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (true);
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

template <class T, class Alloc>
void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	vector<T, Alloc>	temp;

	temp.swap(x);
	x.swap(y);
	y.swap(x);
}

}

#endif
