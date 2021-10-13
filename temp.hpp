/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 16:45:45 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/14 00:17:28 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later
# include <utility>		// for std::pair, should include own pair later
# include <memory>		// for std::allocator

#include "./includes/InputIterator.hpp"
#include "./includes/Pair.hpp"
#include "./includes/BinarySearchTreeIterator.hpp"
#include "./includes/ReimplementedFunctions.hpp"

namespace ft {
template<typename, typename>
class pair;
}

namespace ft {
template <class T = ft::pair<class T1, class T2>>
class node
{
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T			value_type;
		typedef value_type*	pointer;
		typedef value_type&	reference;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~
		node*		left;
		node*		parent;
		node*		right;
		pointer		data;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default constructor
		node(void) : data(nullptr), left(nullptr), parent(nullptr), right(nullptr)
		{
			// std::cout << "Default constructor of node called" << std::endl;
			return ;
		}
		// parameter constructor 1, used to make root node
		node(pointer ptr) : data(ptr), left(nullptr), parent(nullptr), right(nullptr)
		{
			// std::cout << "Parameter constructor root of node called" << std::endl;
			return ;
		}
		// parameter constructor 2, used to make leaf node and connect to parent
		node(node* p, pointer ptr) : data(ptr), left(nullptr), parent(p), right(nullptr)
		{
			// std::cout << "Parameter constructor leaf of node called" << std::endl;
			return ;
		}
		// copy constructor
		node(const node& other)
		{
			*this = other;
			// std::cout << "Copy constructor of node called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~node(void)
		{
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		node&	operator=(const node& other)
		{
			if (this != &other)
			{
				this->data = other.data;
				this->left = other.left;
				this->parent = other.parent;
				this->right = other.right;
			}
			// std::cout << "Assigment operator of node called" << std::endl;
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void)
		{
			return (this->data);
		}
		// dereference operator
		reference operator*(void)
		{
			return (*this->data);
		}

		// --------------------------UTILITY FUNCTIONS--------------------------
		node*	next(void)
		{
			node*	temp = this;
	
			if (temp == nullptr)
			{
				return (nullptr);
			}
			else
			{
				if (temp->right)
				{
					temp = temp->right;
					while (temp && temp->left)
					{
						temp = temp->left;
					}
					return (temp);
				}
				else
				{
					while (temp->parent && temp->parent->right == temp)
					{
						temp = temp->parent;
					}
					return (temp->parent);
				}
			}
		}
		node*	previous(void)
		{
			node*	temp = this;

			if (temp == nullptr)
			{
				return (nullptr);
			}
			else
			{
				if (temp->left)
				{
					temp = temp->left;
					while (temp && temp->right)
					{
						temp = temp->right;
					}
					return (temp);
				}
				else
				{
					while (temp && temp->parent->left == temp)
					{
						temp = temp->parent;
					}
					return (temp->parent);
				}
			}
		}
		void	set_data(node* node)
		{
			this->data = node->data;
		}
};
}

namespace ft {
template <	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T>>>
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
		// typedef std::reverse_iterator<iterator>				reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>		reverse_const_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

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
			this->_alloc = alloc; // do we have to have allocator as an object in the class?
			this->_root = nullptr;
			this->_size = 0;
			return ;
		}
		// range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			difference_type n = 0;

			for (InputIterator begin = first; begin != last; begin++, n++) {}
			this->_alloc = alloc;
			this->_size = n;
			return ;
		}
		// copy constructor
		map(const map& x)
		{
			*this = x;
			return;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~map(void)
		{
			this->clear();
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		map&	operator=(const map& x)
		{
			if (this != &x)
			{
				this->clear();
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_root = x._root;
			}
			return (*this);
		}

		// -------------------------------ITERATORS-----------------------------
		// begin
		iterator	begin(void)
		{
			node<value_type>*	most_left = this->_most_left();
			value_type* 		val = most_left->data;

			return (iterator(val, most_left));
		}

		// -------------------------------CAPACITY------------------------------
		// empty
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
		// size
		size_type	size(void) const
		{
			return (this->_size);
		}
		// max_size
		size_type	max_size(void) const
		{
			return (this->_alloc.max_size());
		}

		// ------------------------------MODIFIERS------------------------------
		//
		ft::pair<node<value_type>*, bool>	insert(const value_type& val)
		{
			node<value_type>* node;

			std::cout << "key = " << val.first << std::endl;
			if (this->_size == 0)
			{
				node = this->_create_node(val);
				this->_root = node;
				this->_size++;
				return (ft::make_pair(node, true));
			}
			node = this->_find(this->_root, val.first);
			if (node != nullptr)
			{
				return (ft::make_pair(node, false)); // change node into map::end
			}
			else
			{
				node = this->_insert_node(this->_root, val);
				this->_check_if_tree_is_balanced(node);
				this->_size++;
				return (ft::make_pair(node, true));
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
			node<value_type>* node = this->_find(this->_root, k);

			if (node == nullptr)
			{
				return (0);
			}
			else
			{
				this->_erase_node(node);
				this->_size--;
				return (1);
			}
		}
		//clear
		void	clear(void)
		{
			ft::node<value_type>*	node_to_delete = nullptr;

			while (this->_root != nullptr)
			{
				node_to_delete = this->_root;
				this->_erase_node(node_to_delete);
			}
			this->_size = 0;
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~
		t_type_of_unbalance	_get_type_of_unbalance(node<value_type>* unbalanced_node, node<value_type>* child, node<value_type>* grandchild)
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

		int	_get_height_subtree(node<value_type>* node)
		{
			if (node == nullptr)
			{
				return (0);
			}

			int	height_left_subtree = this->_get_height_subtree(node->left);
			int	height_right_subtree = this->_get_height_subtree(node->right);

			if (height_left_subtree > height_right_subtree)
			{
				return (height_left_subtree + 1);
			}
			else // height_left_subtree < height_right_subtree
			{
				return (height_right_subtree + 1);
			}
		}

		bool	_check_if_node_is_balanced(node<value_type>* node)
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
	
		void	_check_if_tree_is_balanced(node<value_type>* inserted_node)
		{
			node<value_type>*	temp = inserted_node;
			node<value_type>* 	child = nullptr;
			node<value_type>* 	grandchild = nullptr;
			node<value_type>*	unbalanced_node = nullptr;
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
			return ;
		}

		node<value_type>*	_create_node(const value_type& val)
		{
			std::allocator<ft::node<value_type>>	alloc;
			ft::node<value_type>*					new_node = alloc.allocate(1);
			value_type*								new_pair = this->_alloc.allocate(1);

			this->_alloc.construct(new_pair, value_type(val));
			alloc.construct(new_node, ft::node<value_type>(new_pair));
			std::cout << "created root node with key " << new_node->data->first << std::endl;
			return (new_node);
		}

		node<value_type>*	_create_node(node<value_type>* parent, const value_type& val)
		{
			std::allocator<ft::node<value_type>>	alloc;
			ft::node<value_type>*					new_node = alloc.allocate(1);
			value_type*								new_pair = this->_alloc.allocate(1);

			this->_alloc.construct(new_pair, value_type(val));
			alloc.construct(new_node, ft::node<value_type>(parent, new_pair));
			std::cout << "created leaf node with key " << new_node->data->first << std::endl;
			return (new_node);
		}

		node<value_type>*	_insert_node(node<value_type>* root, const value_type& pair)
		{
			node<value_type>*	temp = root;

			if (pair.first < temp->data->first)
			{
				std::cout << pair.first << " is smaller than " << temp->data->first << std::endl;
				if (temp->left == nullptr)
				{
					root->left = this->_create_node(root, pair);
					return (root->left);
				}
				else
				{
					// std::cout << "move to the left" << std::endl;
					return (this->_insert_node(root->left, pair));
				}
			}
			else if (pair.first > temp->data->first)
			{
				std::cout << pair.first << " is bigger than " << temp->data->first << std::endl;
				if (temp->right == nullptr) 
				{
					root->right = this->_create_node(root, pair);
					return (root->right);
				}
				else
				{
					// std::cout << "move to the right" << std::endl;
					return (this->_insert_node(root->right, pair));
				}
			}
			else // pair.first == (*(*temp)).first
			{
				return (nullptr);
			}
		}

		void	_left_rotation(node<value_type>* pivot, node<value_type>* child)
		{
			if (pivot->parent == nullptr)
			{
				this->_root = child;
				child->parent = nullptr;
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
			if (child->left != nullptr) // if child has left subtree, connect it to the right side of pivot_node
			{
				pivot->right = child->left;
				child->left->parent = pivot;
			}
			else // child does not have left subtree
			{
				pivot->right = nullptr;
			}
			child->left = pivot;
			pivot->parent = child;
		}

		void	_right_rotation(node<value_type>* pivot, node<value_type>* child)
		{
			if (pivot->parent == nullptr)
			{
				this->_root = child;
				child->parent = nullptr;
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
			if (child->right != nullptr) // if child has right subtree, connect it to the left side of pivot_node
			{
				pivot->left = child->right;
				child->right->parent = pivot;
			}	
			else
			{
				pivot->left = nullptr; // child does not have right subtree
			}
			child->right = pivot;
			pivot->parent = child;
		}

		void	perform_balancing(node<value_type>* unbalanced_node, node<value_type>* child, node<value_type>* grandchild, t_type_of_unbalance type_of_unbalance)
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

		void	_erase_node(node<value_type>* node_to_delete)
		{
			std::allocator<node<value_type> >	alloc;
			node<value_type>*					temp = node_to_delete;

			if (!node_to_delete->left && !node_to_delete->right)
			{
				if (node_to_delete == this->_root)
				{
					this->_root = nullptr;
				}
				else
				{
					if (temp->parent->left == temp)
					{
						temp->parent->left = nullptr;
					}
					else
					{
						temp->parent->right = nullptr;
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
					temp->left->parent = nullptr;
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
					temp->right->parent = nullptr;
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

		node<value_type>* _find(node<value_type>* node, const key_type& key)
		{
			if (node == nullptr)
			{
				return (nullptr);
			}
			if (key < node->data->first)
			{
				if (node->left)
					return (this->_find(node->left, key));
				else
					return (nullptr);
			}
			else if (key > node->data->first)
			{
				if (node->right)
					return (this->_find(node->right, key));
				else
					return (nullptr);
			}
			else // key == node_key
				return (node);
		}

		node<value_type>*	_most_left(void)
		{
			node<value_type>* temp = this->_root;

			if (!temp)
			{
				return (nullptr);
			}
			while (temp->left)
			{
				temp = temp->left;
			}
			return (temp);
		}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~
		size_type			_size;
		allocator_type		_alloc;
		node<value_type>*	_root;

	friend class node<value_type>;

};
}

#endif