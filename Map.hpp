/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 16:45:45 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/25 15:05:06 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later
# include <memory>		// for std::allocator

# include "./includes/BinarySearchTreeIterator.hpp"
# include "./includes/InputIterator.hpp"
# include "./includes/Pair.hpp"
# include "./includes/Node.hpp"
# include "./includes/ReimplementedFunctions.hpp"
# include "./includes/ReverseBinarySearchTreeIterator.hpp"

namespace ft {
template<typename, typename>
class pair;
}

namespace ft {
template <	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef BinarySearchTreeIterator<value_type>		iterator;
		// typedef BidirectionalIterator<value_type>			const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>		reverse_const_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;
		typedef ft::node<value_type>						node;

		typedef enum e_type_of_unbalance
		{
			LEFT_LEFT = 1,
			LEFT_RIGHT = 2,
			RIGHT_LEFT = 3,
			RIGHT_RIGHT = 4,
		}	t_type_of_unbalance;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// empty container construct (default constructor)
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			std::allocator<node>	allocator;
			node*					new_begin_node = allocator.allocate(1);
			node*					new_end_node = allocator.allocate(1);

			allocator.construct(new_begin_node, node());
			allocator.construct(new_end_node, node());
			this->_alloc = alloc;
			this->_compare = comp;
			this->_begin = new_begin_node;
			this->_end = new_end_node;
			this->_root = NULL;
			this->_size = 0;
		}
		// range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			difference_type	n = 0;

			for (InputIterator begin = first; begin != last; begin++, n++) {}
			this->_alloc = alloc;
			this->_compare = comp;

			// /*
			// this->_size = ft::distance(first, last, ft::input_iterator_tag);
			// while (first != last)
			// {
			// 	insert(first);
			// 	first++;
			// }
			// return ;
		}
		// copy constructor
		map(const map& x)
		{
			*this = x;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~map(void)
		{
			this->clear();
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		map&	operator=(const map& x)
		{
			if (this != &x)
			{
				this->clear();
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_begin = x._begin;
				this->_end = x._end;
				this->_root = x._root;
			}
			return (*this);
		}

		// -------------------------------ITERATORS-----------------------------
		// begin
		iterator	begin(void)
		{
			return (iterator(this->_most_left()->data, this->_most_left()));
		}

		iterator	end(void)
		{
			return (iterator(NULL, this->_end));
		}

		// reverse_iterator	rbegin(void)
		// {
		// 	std::cout << "in rbegin = " << this->_most_right()->data->first << std::endl;
		// 	return (reverse_iterator(this->_most_right()->data, this->_most_right()));
		// }

		// reverse_iterator	rend(void)
		// {
		// 	return (reverse_iterator(NULL, this->_begin));
		// }

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

		// ----------------------------ELEMENT ACCESS---------------------------
		mapped_type&	operator[](const key_type& k)
		{
			node*	n = this->_find(this->_root, k);

			if (n != NULL)
			{
				// if the key is already present in the map
				// return the second part of the value_type, which is the mapped_type
				return (n->data->second);
			}
			else
			{
				// if the key is not yet present in the map
				// call insert with a pair of k and default constructor of mapped type
				// derefence the iterator (which is the first part of the pair returned from insert)
				// return the second part of the value_type, which is the mapped_type
				return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
			}
		}

		// ------------------------------MODIFIERS------------------------------
		// insert, 1 node based on key
		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			node*	n;

			// std::cout << "key = " << val.first << std::endl;
			if (this->_size == 0)
			{
				n = this->_create_node(val);
				this->_root = n;
				this->_root->left = this->_begin;
				this->_root->right = this->_end;
				this->_begin->parent = this->_root;
				this->_end->parent = this->_root;
				this->_size++;
				return (ft::make_pair(iterator(n->data, n), true));
			}
			n = this->_find(this->_root, val.first);
			if (n != NULL)
			{
				// std::cout << "tried to insert duplicate" << std::endl;
				return (ft::make_pair(iterator(n->data, n), false)); // change node into map::end
			}
			else
			{
				n = this->_insert_node(this->_root, val);
				this->_check_if_tree_is_balanced(n);
				this->_size++;
				this->_most_left()->left = this->_begin;
				this->_most_right()->right = this->_end;
				this->_begin->parent = this->_most_left();
				this->_end->parent = this->_most_right();
				return (ft::make_pair(iterator(n->data, n), true));
			}
		}
		// erase, 1 node based on iterator
		// void	erase(InputIterator position)
		// {
		// 	// call erase with derefenced iterator.first
		// }
		// erase, multiple nodes based on multiple iterators
		// void	erase(InputIterator first, InputIterator last)
		// {
		// 	for (InputIterator begin = first; begin != last; begin++)
		// 	{
		// 		// call erase with dereferenced iterator .first
		// 	}
		// }
		// erase, 1 node based on key
		size_type	erase(const key_type& k)
		{
			node*	n = this->_find(this->_root, k);

			if (n == NULL || n == this->_end)
			{
				return (0);
			}
			else
			{
				this->_erase_node(n);
				this->_size--;
				return (1);
			}
		}
		//clear
		void	clear(void)
		{
			node*					node_to_delete = NULL;
			std::allocator<node>	alloc;

			while (this->_root != NULL)
			{
				node_to_delete = this->_root;
				this->_erase_node(node_to_delete);
			}
			this->_end = NULL;
			this->_size = 0;
		}

		// ------------------------------OBSERVERS------------------------------
		// key comparison object
		key_compare	key_comp(void) const
		{
			return (this->_compare);
		}
		// value comparison object ???
		// value_compare	value_compe(void) const
		// {

		// }

		// -----------------------------OPERATRIONS-----------------------------
		// find
		// iterator find(const key_type& k)
		// {
			// if found return iterator to node

			// else return iterator to this->end();
		// }
		// const_iterator find (const key_type& k) const
		// {
		// 	// if found return const iterator to node

		// 	// else return const iterator to this->end();
		// }
		// count
		size_type	count(const key_type& k) const
		{
			if (this->_find(this->_root, k))
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
		// lower_bound
		// iterator	lower_bound(const key_type& k)
		// {
			// for (iterator = this->begin(); )
		// }
		// const iterator	lower_bound(const key_type& k) const
		// {
			
		// }
		// upper_bound

		// equal_range
		

		// ------------------------------ALLOCATOR------------------------------
		allocator_type get_allocator(void) const
		{
			return (this->_alloc);
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~
		t_type_of_unbalance	_get_type_of_unbalance(node* unbalanced_node, node* child, node* grandchild)
		{
			if (child == unbalanced_node->left && grandchild == child->left)
			{
				return (LEFT_LEFT);
			}
			else if (child == unbalanced_node->left && grandchild == child->right)
			{
				return (LEFT_RIGHT);
			}
			else if (child == unbalanced_node->right && grandchild == child->left)
			{
				return (RIGHT_LEFT);
			}
			else // child == unbalanced_node->right && grandchild == child->right
			{
				return (RIGHT_RIGHT);
			}
		}

		int	_get_height_subtree(node* n)
		{
			if (n == NULL || n == this->_end || n == this->_begin)
			{
				return (0);
			}

			int	height_left_subtree = this->_get_height_subtree(n->left);
			int	height_right_subtree = this->_get_height_subtree(n->right);

			if (height_left_subtree > height_right_subtree)
			{
				return (height_left_subtree + 1);
			}
			else // height_left_subtree < height_right_subtree
			{
				return (height_right_subtree + 1);
			}
		}

		bool	_check_if_node_is_balanced(node* node)
		{
			int	balance_factor;
			int	left;
			int	right;

			left = this->_get_height_subtree(node->left);
			right = this->_get_height_subtree(node->right);
			balance_factor = left - right;
			if (balance_factor > 1 || balance_factor < -1)
			{
				return (false);
			}
			else // -1 0 1 means the node is balanced
			{
				return (true);
			}
		}	
	
		void	_check_if_tree_is_balanced(node* inserted_node)
		{
			node*				temp = inserted_node;
			node* 				child = NULL;
			node* 				grandchild = NULL;
			node*				unbalanced_node = NULL;
			size_t				i = 0;
			t_type_of_unbalance	type_of_unbalance;

			while (temp)
			{
				if (this->_check_if_node_is_balanced(temp) == false)
				{
					unbalanced_node = temp;
					type_of_unbalance = this->_get_type_of_unbalance(unbalanced_node, child, grandchild);
					perform_balancing(unbalanced_node, child, grandchild, type_of_unbalance);
				}
				i++;
				if (i == 1)
				{
					child = temp;
				}
				else if (i >= 2)
				{
					grandchild = child;
					child = temp;
				}
				temp = temp->parent;
			}
		}

		node*	_create_node(const value_type& val)
		{
			std::allocator<node>	alloc;
			node*					new_node = alloc.allocate(1);
			value_type*				new_pair = this->_alloc.allocate(1);

			this->_alloc.construct(new_pair, value_type(val));
			alloc.construct(new_node, node(new_pair));
			std::cout << "created root node with key " << new_node->data->first << std::endl;
			return (new_node);
		}

		node*	_create_node(node* parent, const value_type& val)
		{
			std::allocator<node>	alloc;
			node*					new_node = alloc.allocate(1);
			value_type*				new_pair = this->_alloc.allocate(1);

			this->_alloc.construct(new_pair, value_type(val));
			alloc.construct(new_node, node(parent, new_pair));
			std::cout << "created leaf node with key " << new_node->data->first << std::endl;
			return (new_node);
		}

		node*	_insert_node(node* root, const value_type& pair)
		{
			node*	temp = root;

			if (pair.first < temp->data->first)
			{
				// std::cout << pair.first << " is smaller than " << temp->data->first << std::endl;
				if (temp->left == NULL || temp->left == this->_begin)
				{
					temp->left = this->_create_node(temp, pair);
					return (temp->left);
				}
				else
				{
					// std::cout << "move to the left" << std::endl;
					return (this->_insert_node(temp->left, pair));
				}
			}
			else if (pair.first > temp->data->first)
			{
				// std::cout << pair.first << " is bigger than " << temp->data->first << std::endl;
				if (temp->right == NULL || temp->right == this->_end) 
				{
					temp->right = this->_create_node(temp, pair);
					return (temp->right);
				}
				else
				{
					// std::cout << "move to the right" << std::endl;
					return (this->_insert_node(temp->right, pair));
				}
			}
			else // pair.first == temp->data->first
			{
				return (NULL);
			}
		}

		void	_left_rotation(node* pivot, node* child)
		{
			if (pivot->parent == NULL)
			{
				this->_root = child;
				child->parent = NULL;
			}
			else
			{
				child->parent = pivot->parent;
				if (pivot->parent->left == pivot)
				{
					pivot->parent->left = child;
				}
				else // pivot->parent->right == pivot
				{
					pivot->parent->right = child;
				}
			}
			if (child->left != NULL) // if child has left subtree, connect it to the right side of pivot_node
			{
				pivot->right = child->left;
				child->left->parent = pivot;
			}
			else // child does not have left subtree
			{
				pivot->right = NULL;
			}
			child->left = pivot;
			pivot->parent = child;
		}

		void	_right_rotation(node* pivot, node* child)
		{
			if (pivot->parent == NULL)
			{
				this->_root = child;
				child->parent = NULL;
			}
			else
			{
				child->parent = pivot->parent;
				if (pivot->parent->left == pivot)
				{
					pivot->parent->left = child;
				}
				else // pivot->parent->right == pivot
				{
					pivot->parent->right = child;
				}
			}
			if (child->right != NULL) // if child has right subtree, connect it to the left side of pivot_node
			{
				pivot->left = child->right;
				child->right->parent = pivot;
			}	
			else
			{
				pivot->left = NULL; // child does not have right subtree
			}
			child->right = pivot;
			pivot->parent = child;
		}

		void	perform_balancing(node* unbalanced_node, node* child, node* grandchild, t_type_of_unbalance type_of_unbalance)
		{
			switch (type_of_unbalance)
			{
				case LEFT_LEFT:
				{
					this->_right_rotation(unbalanced_node, child);
					break ;
				}	
				case LEFT_RIGHT:
				{
					this->_left_rotation(child, grandchild);
					this->_right_rotation(unbalanced_node, grandchild);
					break ;
				}
				case RIGHT_LEFT:
				{
					this->_right_rotation(child, grandchild);
					this->_left_rotation(unbalanced_node, grandchild);
					break ;
				}
				case RIGHT_RIGHT:
				{
					this->_left_rotation(unbalanced_node, child);
					break ;
				}
				default:
				{
					break;
				}
			}
		}

		void	_erase_node(node* node_to_delete)
		{
			std::allocator<node>	alloc;
			node*					temp = node_to_delete;

			if (!node_to_delete->left && !node_to_delete->right)
			{
				if (node_to_delete == this->_root)
				{
					this->_root = NULL;
				}
				else
				{
					if (temp->parent->left == temp)
					{
						temp->parent->left = NULL;
					}
					else
					{
						temp->parent->right = NULL;
					}
				}
				std::cout << "erasing node without a child" << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
			}
			else if (node_to_delete->left && !node_to_delete->right)
			{
				if (node_to_delete == this->_root)
				{
					this->_root = temp->left;
					temp->left->parent = NULL;
				}	
				else
				{
					if (temp->parent->left == temp)
					{
						temp->parent->left = temp->left;
						temp->left->parent = temp->parent;
					}
					else
					{
						temp->parent->right = temp->left;
						temp->left->parent = temp->parent;
					}
				}
				std::cout << "erasing node with left child" << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
			}
			else if (!node_to_delete->left && node_to_delete->right)
			{
				if (node_to_delete == this->_root)
				{
					this->_root = temp->right;
					temp->right->parent = NULL;
				}
				else
				{
					if (temp->parent->left == temp)
					{
						temp->parent->left = temp->right;
						temp->right->parent = temp->parent;
					}
					else
					{
						temp->parent->right = temp->right;
						temp->right->parent = temp->parent;
					}
				}
				std::cout << "erasing node with right child" << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
			}
			else if (node_to_delete->left && node_to_delete->right)
			{
				temp = temp->right;
				while (temp->left)
					temp = temp->left;
				node_to_delete->set_data(temp);
				this->_erase_node(temp);
			}
		}

		node* _find(node* node, const key_type& key)
		{
			if (node == NULL)
			{
				return (NULL);
			}
			if (key < node->data->first)
			{
				if (node->left)
					return (this->_find(node->left, key));
				else
					return (NULL);
			}
			else if (key > node->data->first)
			{
				if (node->right && node->right->data != NULL)
					return (this->_find(node->right, key));
				else
					return (NULL);
			}
			else // key == node_key
				return (node);
		}

		node*	_most_left(void)
		{
			node*	temp = this->_root;

			if (!temp)
			{
				return (NULL);
			}
			while (temp->left && temp->left != this->_begin)
			{
				temp = temp->left;
			}
			return (temp);
		}

		node*	_most_right(void)
		{
			node*	temp = this->_root;

			if (!temp)
			{
				return (NULL);
			}
			while (temp->right && temp->right != this->_end)
			{
				temp = temp->right;
			}
			return (temp);
		}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~
		allocator_type	_alloc;
		key_compare		_compare;
		node*			_begin;
		node*			_end;
		node*			_root;
		size_type		_size;

};
}

#endif