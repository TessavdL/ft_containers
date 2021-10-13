/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 12:19:56 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/10 19:28:14 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <algorithm>	// for std::swap
# include <cstddef>		// for size_t and ptrdiff_t
# include <iostream>	// for output
# include <memory>		// for std::allocator

# include "BidirectionalIterator.hpp"
# include "InputIterator.hpp"

// how to typedef the nested class? https://stackoverflow.com/questions/10144034/typedef-of-a-nested-class
// typedef Map::compare								value_compare;

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>>>
class Map
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef BidirectionalIterator<value_type>			iterator;
		// typedef BidirectionalIterator<value_type>			const_iterator;
		// typedef std::reverse_iterator<iterator>				reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>		reverse_const_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~

struct	node
{
	value_type*	key_value;
	node*		left;
	node*		right;
};

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// empty
		explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_root = nullptr;
			this->_size = 0;
			return ;
		}
		// range
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			difference_type n = 0;
			this->_alloc = alloc;
			for (InputIterator begin = first; begin != last; begin++, n++) {}
			this->_size = n;
			return ;
		}
		// copy
		Map(const Map& x)
		{
			this->_alloc = x._alloc;
			this->_root = x._root;
			this->_size = x._size;
			return;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~Map(void)
		{
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		Map&	operator=(const Map& x)
		{
			if (this != &x)
			{
				value_type *temp = this->_alloc(x._size);

				for (size_type i = 0; i < x._size; i++)
				{
					temp + i = x._root + i;
				}
				this->_alloc.deallocate(this->_root);
				this->_root = temp;
				this->_size = x._size;
				this->_alloc = x._alloc;
			}
			return (*this);
		}

		// ------------------------------ITERATORS------------------------------
		iterator	begin(void)
		{
			return (iterator(this->_root->key_value));
		}
		// iterator	end(void)
		// {
		// 	return (iterator(this->_root + this->_size));
		// }
		// reverse_iterator	rbegin(void)
		// {
		// 	return (reverse_iterator(this->_root));
		// }
		// reverse_iterator	rend(void)
		// {
		// 	return (reverse_iterator(this->_root + this->_size));
		// }

		// -------------------------------CAPACITY------------------------------
		// empty
		bool	empty(void)
		{
			if (this->_size == 0)
				return (true);
			else
				return (false);
		}
		// size
		size_type	size(void)
		{
			return (this->_size);
		}
		// size_type	max_size(void)
		// {
		// 	return (0);
		// }

		// // ----------------------------ELEMENT ACCESS---------------------------
		// // mapped_type&	operator[](const key_type& k)
		// // {
		// 	// if k is a match return value
		// 	// if k is not a match insert new element with that key and return a reference to the mapped value
		// 		// increases container size by 1 even if element is constructed without a value
		// 	// does not throw an exception if no key exists
		// 	// (*((this->insert(make_pair(k,mapped_type()))).first)).second
		// // }
		
		// // ------------------------------MODIFIERS------------------------------
		// insert - single element
		std::pair<iterator,bool>	insert(const value_type& val)
		{
			// loop until nullptr
			if (this->_size == 0)
			{
				this->_root = this->_new_node(val);
				this->_size = 1;
				return (std::make_pair(this->begin(), true));
			}	
			while (1)
			{
			if (val.first < this->_root->key_value.first)
			{
				// if there is still more on the left
				if (this->_root->left != nullptr)
				{
					// move on to left node
				}
				// allocate and construct node and return with bool is true
				else
				{
					
				}
			}
			else if (val.first > this->_root->key_value.first)
			{
				// if there is still more on the right
				if (this->_root->right != nullptr)
				{
					// move on to right node
				}
				else
				{
					// allocate and construct node and return with bool is true
				}
			}
			// val.first == node->key_value.first
			else
			{
				// bool is false
			}
			}

	
		}
		// // insert - with hint
		// iterator	insert(iterator position, const value_type& val);
		// // insert - range
		// template <class InputIterator>
		// void	insert (InputIterator first, InputIterator last);

		// // erase - single element - on pos
		// // decreases the size of the container with 1
		// void	erase(iterator position);
		// // erase - single element - key
		// // decreases the size of the container with 1
		// size_type erase(const key_type& k);
		// // erase - range of elements
		// // decreases the size of the container with difference type n = last - first
		// void	erase(iterator first, iterator last);

		// // swap
		// // swaps all the private variables using std::swap
		// void	swap(Map& x);

		// // clear
		// // removes all elements from the map container (which are destroyed), leaving the container with a size of 0
		// void	clear(void);

		// // ------------------------------OBSERVERS------------------------------
		// key_compare	key_comp(void) const;

		// value_compare	value_comp(void) const;

		// // ------------------------------OPERATIONS-----------------------------
		// // find
		// iterator	find(const key_type& k);
		// const_iterator	find(const key_type& k) const;

		// // count
		// // can only return 0 or 1 because all keys in map are unique
		// size_type	count(const key_type& k) const
		// {
		// 	// if a match is found it will return 1
		// 	// if no mathc is found it will return 0
		// 	return (0);
		// }

		// // lower_bound
		// // returns an iterator pointing to the first element in the containers whose key is not considered to go before k
		// // uses key_comp, returns an iterator to the first elemant for which key_comp(element_key k) would return false
		// // if the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is not less than k.
		// // A similar member function, upper_bound, has the same behavior as lower_bound, except in the case that the map contains an element with a key equivalent to k
		// // In this case, lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		// iterator	lower_bound (const key_type& k);
		// const_iterator	lower_bound (const key_type& k) const;

		// // upper_bound
		// // returns an iterator pointing to the first element in the container whose key is considered to go after k.
		// // the function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		// // if the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is greater than k.
		// // asimilar member function, lower_bound, has the same behavior as upper_bound, except in the case that the map contains an element with a key equivalent to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		// iterator	upper_bound (const key_type& k);
		// const_iterator	upper_bound (const key_type& k) const;

		// // equal_range
		// // returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
		// // because the elements in a map container have unique keys, the range returned will contain a single element at most.
		// // if no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).
		// // two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		// std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
		// std::pair<iterator,iterator>	equal_range (const key_type& k);

	// node has left, right and key_val
	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~
		node*	_new_node(const value_type& val)
		{
			node*	new_node = this->_alloc.allocate(sizeof(node));

			this->_alloc.construct(new_node.key_value, val);
			new_node.left = nullptr;
			new_node.right = nullptr;
			return (new_node);
		}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~
		size_type		_size;
		allocator_type	_alloc;
		node*			_root;

};

#endif