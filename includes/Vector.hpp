/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 20:21:15 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/20 15:35:26 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // for cout and endl
# include <memory> // for std::allocator
# include <cstddef> // for size_t
# include <cmath> // for pow

template <typename T, class Allocator = std::allocator<T>>
	class Vector
	{
		public:
			// ---------------------------MEMBER TYPES--------------------------
			typedef T							value_type;
			typedef Allocator					allocator_type;
			typedef std::size_t					size_type;
			// add difference type
			typedef value_type&					reference;
			typedef const value_type& 			const_reference;
			// add allocator pointer
			// add const allocator pointer
			// add iterators	

			// ---------------------------CONSTRUCTORS--------------------------
			// Default constructor
			// constructs an empty container with no elements
			// explicit vector (const allocator_type& alloc = allocator_type());
			Vector(const allocator_type& alloc = allocator_type()) :
				 _alloc(alloc), _capacity(0), _first_element(nullptr), _size(0), _size_value_type(sizeof(value_type))
			{
				std::cout << "Default construtor is called" << std::endl;
				return ;
			}

			// Fill constructor
			// constructs a container with n elements. Each element is a copy of val
			// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _capacity(n), _size(n), _size_value_type(sizeof(value_type))
			{
				this->_first_element = this->_alloc.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					*(this->_first_element + i) = val;
				}
				// for (size_type i = 0; i < this->_size; i++)
				// {
				// 	std::cout << *(this->_first_element + i) << std::endl;
				// }
				std::cout << "Fill construtor is called" << std::endl;
				return ;
			}
			// Range constructor
			// constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			// template <class InputIterator>
				//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

			// Copy constructor
			// constructs a container with a copy of each of the elements in x, in the same order.
			// vector (const vector& x);
			Vector(const Vector& x) :
				_alloc(x._alloc), _capacity(x._capacity), _size(x._size), _size_value_type(x._size_value_type)
			{
				this->_first_element = x._first_element;
				// for (size_type i = 0; i < this->_size; i++)
				// {
				// 	std::cout << *(this->_first_element + i) << std::endl;
				// }
				std::cout << "Copy construtor is called" << std::endl;
				return ;
			}

			// Destructor
			// This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
			~Vector(void)
			{
				std::cout << "Destructor is called" << std::endl;
				return ;
			}

			// -----------------------------CAPACITY----------------------------
			// empty
			// checks whether the container is empty
			bool	empty(void) const
			{
				if (this->_size == 0)
					return (true);
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
				return ((size_type)(pow(2.0, 63.0) / this->_size_value_type) - 1);
			}

			// reserve
			// reserves storage
			void	reserve(size_type new_cap)
			{
				// if new_cap == cap don't do anything
				// if new_cap < cap deallocate everything after new_cap
				// if new_cap > cap allocate extra memory after cap till new_Cap
				return ;
			}

			// capacity
			// returns the number of elements that can be held in currently allocated storage
			size_type	capacity(void) const
			{
				return (this->_capacity);
			}

			// ----------------------------MODIFIERS----------------------------
			// clears
			// clears the contents
			void	clear(void)
			{
				
			}

			// insert
			// inserts elements
			// lot's of polymorphism

			// erase
			// erases elements
			// some polymorphism

			// push_back
			// adds an element to the end
			void	push_back(const T& value)
			{
				
			}

			// pop_back
			// removes the last element
			void	pop_back(void)
			{
				
			}

			// resize
			// changes the number of elements stored
			void	resize(size_type count, value_type value = value_type())
			{
				
			}

			// swap
			// swaps the contents
			void	swap(Vector& other)
			{
				
			}

		private:
			size_type		_capacity;
			size_type		_size_value_type;
			size_type		_size;
			allocator_type _alloc;
			value_type*		_first_element;
	};

// -----------------------------NON-MEMBER FUNCTIONS----------------------------
template <typename T, class Allocator = std::allocator<T>>
bool operator==(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator = std::allocator<T>>
bool operator!=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator = std::allocator<T>>
bool operator<(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator = std::allocator<T>>
bool operator<=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator = std::allocator<T>>
bool operator>(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

template <typename T, class Allocator = std::allocator<T>>
bool operator>=(const Vector<T,Allocator>& lhs, const Vector<T,Allocator>& rhs)
{
	return (true);
}

#endif
