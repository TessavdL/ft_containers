/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 20:21:15 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/24 12:32:24 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>	// for std::swap
# include <cstddef>		// for size_t and ptrdiff_t
# include <iostream>	// for output
# include <memory>		// for std::allocator

# include "./RandomAccessIterator.hpp"
# include "./InputIterator.hpp"

template <class T, class Allocator = std::allocator<T> >
	class Vector
	{
		public:
			// ---------------------------MEMBER TYPES--------------------------
			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef value_type&							reference;
			typedef const value_type& 					const_reference;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;

			// typedef typename allocator_type::pointer				pointer;
			// typedef typename allocator_type::const_pointer		const_pointer;

			typedef RandomAccessIterator<value_type>	iterator;

			// ---------------------------CONSTRUCTORS--------------------------
			// Default constructor
			// constructs an empty container with no elements
			// explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector(const allocator_type& alloc = allocator_type()) :
				 _alloc(alloc), _capacity(0), _first_element(nullptr), _size(0)
			{
				// std::cout << "Default construtor is called" << std::endl;
			}

			// Fill constructor
			// constructs a container with n elements. Each element is a copy of val
			// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _capacity(n), _size(n)
			{
				this->_first_element = this->_alloc.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(this->_first_element + i, val);
				}
				// std::cout << "Fill construtor is called" << std::endl;
			}
			// Range constructor
			// constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			// template <typename>
			// class InputIterator;
			
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				difference_type n = 0;
				while (first != last)
				{
					n++;
					std::cout << *first << std::endl;
					first++;
				}
				this->_size = n;
				std::cout << n << std::endl;
			}

			// Copy constructor
			// constructs a container with a copy of each of the elements in x, in the same order.
			// vector (const vector& x);
			vector(const vector& x) :
				_alloc(x._alloc), _capacity(x._capacity), _size(x._size)
			{
				this->_first_element = this->_alloc.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(this->_first_element + i, *(x._first_element + i));
				}
				// std::cout << "Copy construtor is called" << std::endl;
			}

			// Destructor
			// This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
			~vector(void)
			{
			// 	if (this->_size > 0)
			// 	{
			// 		this->clear();
			// 	}
			// 	if (this->_capacity > 0)
			// 	{
			// 		this->_alloc.deallocate(this->_first_element, this->_capacity);
			// 	}
				// std::cout << "Destructor is called" << std::endl;
			}

			// operator=
			// vector& operator= (vector const& other);
			// return (*this);

			// assign
			// void assign (size_type count, T const& value);
			// template <class InutIt>
			// void assign (InputIt first, InputIt last);

			// allocator_type get_allocator() const;
			// returns the associated allocator

			// --------------------------ELEMENT ACCESS-------------------------
			// at
			// returns reference to requested element
			// if pos = size or pos > size throw exeception
			reference	at(size_type pos)
			{
				// if (pos >= this->_size)
				return (this->_first_element[pos]);
			}

			const_reference	at(size_type pos) const
			{
				// if (pos >= this->_size)
				return (this->_first_element[pos]);
			}

			// operator []
			// does not test for bounds, accessing non existant element is undefined behavior
			// does not insert a new element (unline std::map)
			reference operator[](size_type pos)
			{
				return (this->_first_element[pos]);
			}

			const_reference operator[](size_type pos) const
			{
				return (this->_first_element[pos]);
			}

			// front
			// calling front on empty container is causes undefined behavior
			reference	front(void)
			{
				return (this->_first_element[0]);
			}

			const_reference	front(void) const
			{
				return (this->_first_element[0]);
			}

			// back
			// calling back on empty container is causes undefined behavior
			reference	back(void)
			{
				return (this->_first_element[this->_size - 1]);
			}

			const_reference	back(void) const
			{
				return (this->_first_element[this->_size - 1]);
			}

			// data
			// returns a pointer to the underlying element storage
			// for non-empty containers this is the address of the first element
			T*	data(void)
			{
				return (this->_first_element);
			}

			const T*	data(void) const
			{
				return (this->_first_element);
			}

			// ----------------------------ITERATORS----------------------------
			iterator	begin(void)
			{
				return (iterator(this->_first_element));
			}

			iterator	end(void)
			{
				return (iterator(this->_first_element + this->_size));
			}

			// -----------------------------CAPACITY----------------------------
			// empty
			// checks whether the container is empty
			bool	empty(void) const
			{
				if (this->_size == 0)
				{
					return (true);
				}
				return (false);
			}

			// size
			// returns the number of elements
			size_type	size(void) const
			{
				return (this->_size);
			}

			// max_size
			// returns the maximum possible number of elements
			size_type	max_size(void) const
			{
				// return ((size_type)(pow(2.0, 63.0) / this->_size_value_type) - 1);
				return (this->_alloc.max_size());
			}

			// reserve
			// reserves storage if the new capacity is bigger than the current capacity
			// size remains the same
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
				return ;
			}

			// capacity
			// returns the number of elements that can be held in currently allocated storage
			size_type	capacity(void) const
			{
				return (this->_capacity);
			}

			// ----------------------------MODIFIERS----------------------------
			// clear
			// clears the contents using destory from the allocator
			// does not deallocate memory
			// size becomes 0 but capacity is unchanged
			void	clear(void)
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.destroy(this->_first_element + i);
				}
				this->_size = 0;
				return ;
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

			void insert(iterator pos, size_type count, const T& value)
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
			#include <stdio.h>
			template<class InputIt>
			void insert(iterator pos, InputIt first, InputIt last)
			{
				difference_type	n = pos - this->begin();
				difference_type	count = 0;
				InputIt temp = first;

				while (temp != last)
				{
					count++;
					temp++;
				}

				std::cout << "n = " << n << " count = " << count << " capacity = " << this->_capacity << " size = " << this->_size << std::endl;

				if (this->_capacity == 0)
				{
					this->_allocate_new(count, *first);
					return ;
				}
				if (this->_size + count > this->_capacity)
				{
					std::cout << " here " << std::endl;
					if (this->_capacity * 2 < this->_size + count)
					{
						std::cout << " here 2 " << std::endl;
						this->_reallocate(this->_size + count);
					}
					else
					{
						std::cout << " here 3 " << std::endl;
						this->_reallocate(this->_capacity * 2);
					}
				}
					
				std::cout << "increased capacity = ";
				std::cout << this->_capacity << std::endl;
				std::cout << "count = " << count << std::endl;

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

			// erase
			// invalid pos causes undefined behavor
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

			// push_back
			// adds an element to the end
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
				return ;
			}

			// pop_back
			// appends the given element value to the last element of the container
			// calling pop_back on an empty container results in undefined behavior
			void	pop_back(void)
			{
				this->_alloc.destroy(this->_first_element + (this->_size - 1));
				this->_size--;
				return ;
			}

			// resize
			// changes the number of elements stored
			void	resize(size_type count, T value = T())
			{
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
				return ;
			}

			// swap
			// swaps the contents of this vector with the contents of the other vector
			void	swap(vector<value_type>& other)
			{
				std::swap(this->_alloc, other._alloc);
				std::swap(this->_capacity, other._capacity);
				std::swap(this->_first_element, other._first_element);
				std::swap(this->_size, other._size);
			}

		private:
			// template<class InputIt>
			// void	_allocate_new(InputIt first, InputIt last)
			// {
			// 	difference_type new_capacity = last - first;
				
			// 	this->_first_element = this->_alloc.allocate(new_capacity);
			// 	for (size_type i = 0; i < new_capacity; i++)
			// 	{
			// 		this->_alloc.construct(this->_first_element + i, *(first + i));
			// 	}
			// 	this->_capacity = new_capacity;
			// 	this->_size = new_capacity;
			// }
			void	_allocate_new(iterator first, iterator last)
			{
				difference_type new_capacity = last - first;
				
				this->_first_element = this->_alloc.allocate(new_capacity);
				for (size_type i = 0; i < new_capacity; i++)
				{
					this->_alloc.construct(this->_first_element + i, *(first + i));
				}
				this->_capacity = new_capacity;
				this->_size = new_capacity;
			}

			void	_allocate_new(size_type new_capacity, const T& value)
			{
				this->_first_element = this->_alloc.allocate(new_capacity);
				for (size_type i = 0; i < new_capacity; i++)
				{
					this->_alloc.construct(this->_first_element + i, value);
				}
				this->_capacity = new_capacity;
				this->_size = new_capacity;
			}

			// _reallocate
			//	allocates memory for a new container and constructs the elements based on the old container
			//	destroys the old container elements and deallocates its memory
			//	sets the new capacity but does not set the size
			void	_reallocate(size_type new_capacity)
			{
				value_type*	temp = this->_alloc.allocate(new_capacity);

				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(temp + i, *(this->_first_element + i));
					this->_alloc.destroy(this->_first_element + i);
				}
				this->_alloc.deallocate(this->_first_element, this->_capacity);
				this->_first_element = temp;
				this->_capacity = new_capacity;
				return ;
			}

			allocator_type	_alloc;
			size_type		_capacity;
			value_type*		_first_element;
			size_type		_size;
	};

// -----------------------------NON-MEMBER FUNCTIONS----------------------------
template <typename T, class Allocator >
bool operator==(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (true);
}

template <typename T, class Allocator >
bool operator!=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <typename T, class Allocator >
bool operator<(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator >
bool operator>(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator  >
bool operator<=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (!(lhs > rhs));
}

template <typename T, class Allocator >
bool operator>=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (!(lhs < rhs));
}
}

#endif
