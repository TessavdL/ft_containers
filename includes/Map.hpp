/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 16:45:45 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/01 17:53:03 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>	// for std::less, should include own compare later and for std::binary_function
# include <iostream>	// for output, prob remove later
# include <memory>		// for std::allocator

# include "./BinarySearchTreeIterator.hpp"
# include "./IteratorTraits.hpp"
# include "./Node.hpp"
# include "./Pair.hpp"
# include "./ReimplementedFunctions.hpp"
# include "./ReverseIterator.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<const key_type, mapped_type>				value_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef ft::node<value_type>								node;
		typedef BinarySearchTreeIterator<value_type, node>			iterator;
		typedef BinarySearchTreeIterator<const value_type, node>	const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::ptrdiff_t										difference_type;
		typedef std::size_t											size_type;

		typedef enum e_type_of_unbalance
		{
			LEFT_LEFT = 1,
			LEFT_RIGHT = 2,
			RIGHT_LEFT = 3,
			RIGHT_RIGHT = 4
		}	t_type_of_unbalance;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NESTED CLASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool	operator()(const value_type& x, const value_type& y) const
				{
					return (comp(x.first, y.first));
				}
			protected:
				key_compare	comp;
				value_compare (key_compare c) : comp(c) {}
		};

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _compare(comp), _begin(NULL), _end(NULL), _root(NULL), _size(0)
		{
			// std::cout << "Default construtor is called" << std::endl;
		}
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _compare(comp), _begin(NULL), _end(NULL), _root(NULL), _size(0)
		{
			typename ft::iterator_traits<InputIterator>::difference_type n = ft::distance(first, last);

			if (n > 0)
			{
				for (; first != last; first++)
				{
					this->insert(*first);
				}
			}
			// std::cout << "Range construtor is called" << std::endl;
		}
		map(const map& x) :
			_alloc(x._alloc), _compare(x._compare), _begin(NULL), _end(NULL), _root(NULL), _size(0)
		{
			*this = x;
			// std::cout << "Copy construtor is called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~map(void)
		{
			this->clear();
			// std::cout << "Destructor is called" << std::endl;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		map&	operator=(const map& x)
		{
			if (this != &x)
			{
				this->clear();
				this->_alloc = x._alloc;
				this->_compare = x._compare;
				this->insert(x.begin(), x.end());
			}
			// std::cout << "Assignment operator is called" << std::endl;
			return (*this);
		}

		// -------------------------------ITERATORS-----------------------------
		iterator	begin(void)
		{
			if (this->_size == 0)
			{
				return (iterator(NULL, this->_find_most_left_node()));
			}
			return (iterator(this->_find_most_left_node()->data, this->_find_most_left_node()));
		}
		const_iterator	begin(void) const
		{
			if (this->_size == 0)
			{
				return (const_iterator(NULL, this->_find_most_left_node()));
			}
			return (const_iterator(const_cast<value_type*>(this->_find_most_left_node()->data), this->_find_most_left_node()));
		}
		iterator	end(void)
		{
			return (iterator(NULL, this->_end));
		}
		const_iterator	end(void) const
		{
			return (const_iterator(NULL, this->_end));
		}
		reverse_iterator	rbegin(void)
		{
			return (reverse_iterator(iterator(NULL, this->_end)));
		}
		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(const_iterator(NULL, this->_end)));
		}
		reverse_iterator	rend(void)
		{
			if (this->_size == 0)
			{
				return (reverse_iterator(iterator(NULL, this->_find_most_left_node())));
			}
			return (reverse_iterator(iterator(this->_find_most_left_node()->data, this->_find_most_left_node())));
		}
		const_reverse_iterator	rend(void) const
		{
			if (this->_size == 0)
			{
				return (const_reverse_iterator(const_iterator(NULL, this->find_most_left_node())));
			}
			return (const_reverse_iterator(const_iterator(NULL, this->_begin)));
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

		// ----------------------------ELEMENT ACCESS---------------------------
		mapped_type&	operator[](const key_type& k)
		{
			node*	n = this->_find_node(this->_root, k);

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
		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			node*	n;

			if (this->_size == 0)
			{
				n = this->_create_node(val);
				this->_create_begin_and_end_node();
				this->_root = n;
				this->_begin->parent = this->_root;
				this->_end->parent = this->_root;
				this->_size++;
				return (ft::make_pair(iterator(n->data, n), true));
			}
			n = this->_find_node(this->_root, val.first);
			if (n != NULL)
			{
				return (ft::make_pair(iterator(n->data, n), false));
			}
			else
			{
				n = this->_insert_node(this->_root, val);
				this->_check_if_tree_is_balanced(n);
				this->_size++;
				this->_begin->parent = this->_find_most_left_node();
				this->_end->parent = this->_find_most_right_node();
				return (ft::make_pair(iterator(n->data, n), true));
			}
		}
		// this function can be used to optimize insertion, removing the need to use find
		iterator	insert(iterator position, const value_type& val)
		{
			ft::pair<iterator, bool>	ret = this->insert(val);

			(void)position;
			return (ret.first);
		}
		template <class InputIterator>
  		void	insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
			{
				this->insert(*first);		
			}
		}
		void	erase(iterator position)
		{
			this->erase(*position);
		}
		void	erase(iterator first, iterator last)
		{
			for (; first != last; first++)
			{
				this->erase(*first);
			}
		}
		size_type	erase(const key_type& k)
		{
			node*	n = this->_find_node(this->_root, k);
			node*	parent;

			if (n == NULL)
			{
				return (0);
			}
			else
			{
				parent = n->parent;
				this->_erase_node(n);
				this->_size--;
				this->_check_if_tree_is_balanced(parent);
				this->_begin->parent = this->_find_most_left_node();
				this->_end->parent = this->_find_most_right_node();
				return (1);
			}
		}
		void	clear(void)
		{
			node*					node_to_delete = NULL;
			std::allocator<node>	alloc;

			while (this->_root != NULL)
			{
				node_to_delete = this->_root;
				this->_erase_node(node_to_delete);
			}
			this->_begin = NULL;
			this->_end = NULL;
			this->_size = 0;
		}

		// ------------------------------OBSERVERS------------------------------
		key_compare	key_comp(void) const
		{
			return (this->_compare);
		}
		value_compare	value_comp(void) const
		{
			return (value_compare(this->_compare));
		}

		// ------------------------------OPERATIONS-----------------------------
		iterator find(const key_type& k)
		{
			node*	n = this->_find_node(this->_root, k);

			if (n == NULL)
			{
				return (this->end());
			}
			else
			{
				return (iterator(n->data, n));
			}
		}
		const_iterator find (const key_type& k) const
		{
			node*	n = this->_find_node(this->_root, k);

			if (n == NULL)
			{
				return (this->end());
			}
			else
			{
				return (const_iterator(const_cast<value_type*>(n->data), n));
			}
		}
		size_type	count(const key_type& k) const
		{
			if (this->_find_node(this->_root, k))
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
		iterator	lower_bound(const key_type& k)
		{
			iterator	lower_bound = this->find(k);

			if (lower_bound != this->end())
			{
				return (lower_bound);
			}
			else
			{
				for (lower_bound = this->begin(); lower_bound != this->end(); lower_bound++)
				{
					if ((*lower_bound).first > k)
					{
						break ;
					}
				}
				return (lower_bound);
			}
		}
		const_iterator	lower_bound(const key_type& k) const
		{
			const_iterator	lower_bound = this->find(k);

			if (lower_bound != this->end())
			{
				return (lower_bound);
			}
			else
			{
				for (lower_bound = this->begin(); lower_bound != this->end(); lower_bound++)
				{
					if ((*lower_bound).first > k)
					{
						break ;
					}
				}
				return (lower_bound);
			}
		}
		iterator	upper_bound (const key_type& k)
		{
			iterator	upper_bound = this->find(k);

			if (upper_bound != this->end())
			{
				return (upper_bound);
			}
			else
			{
				for (reverse_iterator rit = this->rbegin(); rit != this->rend(); rit++)
				{

				}
				return (upper_bound);
			}
		}
		// const_iterator	upper_bound (const key_type& k) const
		// {

		// }
		// ft::pair<iterator,iterator>	equal_range (const key_type& k)
		// {

		// }
		// ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
		// {

		// }

		// ------------------------------ALLOCATOR------------------------------
		allocator_type get_allocator(void) const
		{
			return (this->_alloc);
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~
		// -----------------------------CREATE NODE-----------------------------
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
		void	_create_begin_and_end_node(void)
		{
			std::allocator<node>	allocator;
			node*					new_begin_node = allocator.allocate(1);
			node*					new_end_node = allocator.allocate(1);

			allocator.construct(new_begin_node, node());
			allocator.construct(new_end_node, node());
			this->_begin = new_begin_node;
			this->_end = new_end_node;
		}

		// -----------------------------INSERT NODE-----------------------------
		node*	_insert_node(node* root, const value_type& pair)
		{
			node*	temp = root;

			if (pair.first < temp->data->first)
			{
				// std::cout << pair.first << " is smaller than " << temp->data->first << std::endl;
				if (temp->left == NULL)
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
				if (temp->right == NULL) 
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
			// else // pair.first == temp->data->first
			{
				return (NULL);
			}
		}

		// ------------------------------ERASE NODE-----------------------------
		void	_erase_node(node* node_to_delete)
		{
			std::allocator<node>	alloc;
			node*					temp = node_to_delete;

			// std::cout << "node to delete in _erase_node "  << (*node_to_delete->data).first << std::endl;
			// std::cout << "root in _erase_node " << (*this->_root->data).first << std::endl;
			if (node_to_delete == NULL)
			{
				return ;
			}
			if (!node_to_delete->left && !node_to_delete->right)
			{
				// std::cout << "node to delete LEFT NO RIGHT NO " << (*node_to_delete->data).first << std::endl;				
				if (node_to_delete == this->_root)
				{
					// std::cout << "node to delete is equal to root" << std::endl;
					this->_root = NULL;
					alloc.destroy(this->_begin);
					alloc.deallocate(this->_begin, 1);
					this->_begin = NULL;
					alloc.destroy(this->_end);
					alloc.deallocate(this->_end, 1);
					this->_end = NULL;
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
				// std::cout << "erasing node without a child "  << (*node_to_delete->data).first << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
				// std::cout << "erased node" << std::endl;
			}
			else if (!node_to_delete->left && node_to_delete->right)
			{
				// std::cout << "node to delete LEFT NO RIGHT YES " << (*node_to_delete->data).first << std::endl;
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
				// std::cout << "erasing node with left child " << (*node_to_delete->data).first << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
				// std::cout << "erased node" << std::endl;
			}
			else if (node_to_delete->left && !node_to_delete->right)
			{
				// std::cout << "node to delete LEFT YES RIGHT NO " << (*node_to_delete->data).first << std::endl;
				if (node_to_delete == this->_root)
				{
					// std::cout << "YES" << std::endl;
					this->_root = temp->left;
					temp->left->parent = NULL;
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
				// std::cout << "erasing node with right child "  << (*node_to_delete->data).first << std::endl;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.deallocate(node_to_delete->data, 1);
				alloc.destroy(node_to_delete);
				alloc.deallocate(node_to_delete, 1);
				// std::cout << "erased node" << std::endl;
			}
			else if (node_to_delete->left && node_to_delete->right)
			{
				// std::cout << "both" << std::endl;
				temp = temp->right;
				while (temp->left)
					temp = temp->left;
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.construct(node_to_delete->data, (*temp->data));
				this->_erase_node(temp);
			}
		}

		// ------------------------------FIND NODE------------------------------
		node* _find_node(node* node, const key_type& key) const
		{
			if (node == NULL)
			{
				return (NULL);
			}
			if (key < node->data->first)
			{
				if (node->left)
					return (this->_find_node(node->left, key));
				else
					return (NULL);
			}
			else if (key > node->data->first)
			{
				if (node->right && node->right->data != NULL)
					return (this->_find_node(node->right, key));
				else
					return (NULL);
			}
			else // key == node_key
				return (node);
		}

		node*	_find_most_left_node(void) const
		{
			node*	temp = this->_root;

			if (!temp)
			{
				return (NULL);
			}
			while (temp->left)
			{
				temp = temp->left;
			}
			return (temp);
		}

		node*	_find_most_right_node(void) const
		{
			node*	temp = this->_root;

			if (!temp)
			{
				return (NULL);
			}
			while (temp->right)
			{
				temp = temp->right;
			}
			return (temp);
		}

		// ------------------------------BALANCING------------------------------
		t_type_of_unbalance	_get_type_of_unbalance(node* unbalanced_node, node* child, node* grandchild)
		{
			if (child == unbalanced_node->left && grandchild == child->left)
			{
				// std::cout << "left left" << std::endl;
				return (LEFT_LEFT);
			}
			else if (child == unbalanced_node->left && grandchild == child->right)
			{
				// std::cout << "left right" << std::endl;
				return (LEFT_RIGHT);
			}
			else if (child == unbalanced_node->right && grandchild == child->left)
			{
				// std::cout << "right left" << std::endl;
				return (RIGHT_LEFT);
			}
			else // child == unbalanced_node->right && grandchild == child->right
			{
				// std::cout << "right right" << std::endl;
				return (RIGHT_RIGHT);
			}
		}

		int	_get_height_subtree(node* n)
		{
			if (n == NULL)
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
			// std::cout << "key = " << (*node->data).first << " balance_factor " << balance_factor << std::endl;
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
					// std::cout << "unbalanced node = " << (*temp->data).first << " child node = " << (*child->data).first <<" grandchild node = " << (*grandchild->data).first << std::endl;
					unbalanced_node = temp;
					type_of_unbalance = this->_get_type_of_unbalance(unbalanced_node, child, grandchild);
					perform_balancing(unbalanced_node, child, grandchild, type_of_unbalance);
					return ;
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
