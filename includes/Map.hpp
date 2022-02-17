/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 16:45:45 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/30 16:11:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>		// for std::allocator

# include "./BinarySearchTreeIterator.hpp"
# include "./IteratorTraits.hpp"
# include "./Node.hpp"
# include "./Pair.hpp"
# include "./ReimplementedFunctions.hpp"
# include "./ReverseIterator.hpp"

namespace ft {

template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~NESTED FUNCTION CLASS~~~~~~~~~~~~~~~~~~~~~~~~~
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
			friend class map;
			public:
			// ~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

			// ~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~
				bool	operator()(const value_type& x, const value_type& y) const
				{
					return (this->comp(x.first, y.first));
				}

			protected:
			// ~~~~~~~~~~~~~~~~~~~~~~PROTECTED MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~
				key_compare	comp;

			// ~~~~~~~~~~~~~~~~~~~~PROTECTED MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~
				value_compare(key_compare c) : comp(c) {}
		};

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _compare(comp), _begin(NULL), _end(NULL), _root(NULL), _size(0) {}

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
		}

		map(const map& x) :
			_alloc(x._alloc), _compare(x._compare), _begin(NULL), _end(NULL), _root(NULL), _size(0)
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
				this->_compare = x._compare;
				this->insert(x.begin(), x.end());
			}
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
			return (const_iterator(this->_find_most_left_node()->data, this->_find_most_left_node()));
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
			return (const_reverse_iterator(const_iterator(this->_find_most_left_node()->data, this->_find_most_left_node())));
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
			if (n != NULL)	// val already exists
			{
				return (ft::make_pair(iterator(n->data, n), false));
			}
			else
			{
				n = this->_insert_node(this->_root, val);
				this->_check_balance_after_insertion(n);
				this->_begin->parent = this->_find_most_left_node();
				this->_end->parent = this->_find_most_right_node();
				this->_size++;
				return (ft::make_pair(iterator(n->data, n), true));
			}
		}

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
			this->erase((*position).first);
		}

		void	erase(iterator first, iterator last)
		{
			iterator	del;

			while (first != last)
			{
				del = first;
				first++;
				this->erase((*del).first);
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
				this->_delete_node(n);
				this->_size--;
				this->_check_balance_after_deletion(parent);
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
				this->_delete_node(node_to_delete);
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

		const_iterator find(const key_type& k) const
		{
			node*	n = this->_find_node(this->_root, k);

			if (n == NULL)
			{
				return (this->end());
			}
			else
			{
				return (const_iterator(n->data, n));
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
			iterator	lower_bound = this->begin();

			for (; lower_bound != this->end(); lower_bound++)
			{
				if (key_comp()((*lower_bound).first, k) == false)
				{
					break ;
				}
			}
			return (lower_bound);
		}

		const_iterator	lower_bound(const key_type& k) const
		{
			const_iterator	lower_bound = this->begin();

			for (; lower_bound != this->end(); lower_bound++)
			{
				if (key_comp()((*lower_bound).first, k) == false)
				{
					break ;
				}
			}
			return (lower_bound);
		}

		iterator	upper_bound(const key_type& k)
		{
			iterator	upper_bound = this->begin();

			for (; upper_bound != this->end(); upper_bound++)
			{
				if (key_comp()(k, (*upper_bound).first) == true)
				{
					break ;
				}
			}
			return (upper_bound);
		}

		const_iterator	upper_bound(const key_type& k) const
		{
			const_iterator	upper_bound = this->begin();

			for (; upper_bound != this->end(); upper_bound++)
			{
				if (key_comp()(k, (*upper_bound).first) == true)
				{
					break ;
				}
			}
			return (upper_bound);
		}

		ft::pair<iterator,iterator>	equal_range(const key_type& k)
		{
			iterator	lower_bound = this->lower_bound(k);
			iterator	upper_bound = this->upper_bound(k);

			return (ft::make_pair(lower_bound, upper_bound));
		}

		ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
		{
			const_iterator	lower_bound = this->lower_bound(k);
			const_iterator	upper_bound = this->upper_bound(k);

			return (ft::make_pair(lower_bound, upper_bound));
		}

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
			return (new_node);
		}

		node*	_create_node(node* parent, const value_type& val)
		{
			std::allocator<node>	alloc;
			node*					new_node = alloc.allocate(1);
			value_type*				new_pair = this->_alloc.allocate(1);

			this->_alloc.construct(new_pair, value_type(val));
			alloc.construct(new_node, node(parent, new_pair));
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
				if (temp->left == NULL)
				{
					temp->left = this->_create_node(temp, pair);
					return (temp->left);
				}
				else
				{
					return (this->_insert_node(temp->left, pair));
				}
			}
			else if (pair.first > temp->data->first)
			{
				if (temp->right == NULL) 
				{
					temp->right = this->_create_node(temp, pair);
					return (temp->right);
				}
				else
				{
					return (this->_insert_node(temp->right, pair));
				}
			}
			else	// pair.first == temp->data->first
			{
				return (NULL);
			}
		}

		// ------------------------------ERASE NODE-----------------------------
		void	_delete_node_without_subtree(node* node_to_delete, std::allocator<node>& alloc)
		{
			if (node_to_delete == this->_root)
			{
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
				if (node_to_delete->parent->left == node_to_delete)
				{
					node_to_delete->parent->left = NULL;
				}
				else
				{
					node_to_delete->parent->right = NULL;
				}
			}
			this->_alloc.destroy(node_to_delete->data);
			this->_alloc.deallocate(node_to_delete->data, 1);
			alloc.destroy(node_to_delete);
			alloc.deallocate(node_to_delete, 1);
		}

		void	_delete_node_with_left_subtree(node* node_to_delete, std::allocator<node>& alloc)
		{
			if (node_to_delete == this->_root)
			{
				this->_root = node_to_delete->left;
				node_to_delete->left->parent = NULL;
			}
			else
			{
				if (node_to_delete->parent->left == node_to_delete)
				{
					node_to_delete->parent->left = node_to_delete->right;
					node_to_delete->right->parent = node_to_delete->parent;
				}
				else
				{
					node_to_delete->parent->right = node_to_delete->right;
					node_to_delete->right->parent = node_to_delete->parent;
				}
			}
			this->_alloc.destroy(node_to_delete->data);
			this->_alloc.deallocate(node_to_delete->data, 1);
			alloc.destroy(node_to_delete);
			alloc.deallocate(node_to_delete, 1);
		}

		void	_delete_node_with_right_subtree(node* node_to_delete, std::allocator<node>& alloc)
		{
			if (node_to_delete == this->_root)
			{
				this->_root = node_to_delete->right;
				node_to_delete->right->parent = NULL;
			}	
			else
			{
				if (node_to_delete->parent->left == node_to_delete)
				{
					node_to_delete->parent->left = node_to_delete->right;
					node_to_delete->right->parent = node_to_delete->parent;
				}
				else
				{
					node_to_delete->parent->right = node_to_delete->right;
					node_to_delete->right->parent = node_to_delete->parent;
				}
			}
			this->_alloc.destroy(node_to_delete->data);
			this->_alloc.deallocate(node_to_delete->data, 1);
			alloc.destroy(node_to_delete);
			alloc.deallocate(node_to_delete, 1);
		}

		void	_delete_node(node* node_to_delete)
		{
			std::allocator<node>	alloc;
			node*					temp = node_to_delete;

			if (node_to_delete == NULL)
			{
				return ;
			}
			if (!node_to_delete->left && !node_to_delete->right)
			{
				this->_delete_node_without_subtree(node_to_delete, alloc);
			}
			else if (node_to_delete->left && !node_to_delete->right)
			{
				this->_delete_node_with_left_subtree(node_to_delete, alloc);
			}
			else if (!node_to_delete->left && node_to_delete->right)
			{
				this->_delete_node_with_right_subtree(node_to_delete, alloc);
			}
			else	// node has left and rght subtree
			{
				temp = temp->right;
				while (temp->left)
				{
					temp = temp->left;
				}
				this->_alloc.destroy(node_to_delete->data);
				this->_alloc.construct(node_to_delete->data, (*temp->data));
				this->_delete_node(temp);
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
				{
					return (this->_find_node(node->left, key));
				}
				else
				{
					return (NULL);
				}
			}
			else if (key > node->data->first)
			{
				if (node->right && node->right->data != NULL)
				{
					return (this->_find_node(node->right, key));
				}
				else
				{
					return (NULL);
				}
			}
			else	// key == node_key
			{
				return (node);
			}
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
		t_type_of_unbalance	_get_type_of_unbalance(node* unbalanced_node, node* child, node* grandchild) const
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
			else	// child == unbalanced_node->right && grandchild == child->right
			{
				return (RIGHT_RIGHT);
			}
		}

		int	_get_height_subtree(node* n) const
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
			else	// height_left_subtree <= height_right_subtree
			{
				return (height_right_subtree + 1);
			}
		}

		int	_get_balance_factor(node* node) const
		{
			int	left = this->_get_height_subtree(node->left);
			int	right = this->_get_height_subtree(node->right);

			return (left - right);
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
				else	// pivot->parent->right == pivot
				{
					pivot->parent->right = child;
				}
			}
			if (child->left != NULL)	// if child has left subtree, connect it to the right side of pivot_node
			{
				pivot->right = child->left;
				child->left->parent = pivot;
			}
			else	// child does not have left subtree
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
				else	// pivot->parent->right == pivot
				{
					pivot->parent->right = child;
				}
			}
			if (child->right != NULL)	// if child has right subtree, connect it to the left side of pivot_node
			{
				pivot->left = child->right;
				child->right->parent = pivot;
			}	
			else
			{
				pivot->left = NULL;	// child does not have right subtree
			}
			child->right = pivot;
			pivot->parent = child;
		}

		void	_balance_node(node* unbalanced_node, node* child, node* grandchild, t_type_of_unbalance type_of_unbalance)
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

		void	_check_balance_after_deletion(node* parent_of_deleted_node)
		{
			int		balance_factor;
			int		height_left_subtree;
			int		height_right_subtree;
			node*	unbalanced_node = NULL;

			for (node* temp = parent_of_deleted_node; temp; temp = temp->parent)
			{
				balance_factor = this->_get_balance_factor(temp);
				if (balance_factor < -1)	// node is unbalanced and right tree is bigger than left tree
				{
					unbalanced_node = temp;
					height_left_subtree = this->_get_height_subtree(unbalanced_node->right->left);
					height_right_subtree = this->_get_height_subtree(unbalanced_node->right->right);
					if (height_left_subtree < height_right_subtree)
					{
						_balance_node(unbalanced_node, unbalanced_node->right, unbalanced_node->right->left, RIGHT_LEFT);
					}
					else
					{
						_balance_node(unbalanced_node, unbalanced_node->right, NULL, RIGHT_RIGHT);
					}
				}
				else if (balance_factor > 1)	// node is unbalanced and left tree is bigger than right tree
				{
					unbalanced_node = temp;
					height_left_subtree = this->_get_height_subtree(unbalanced_node->left->left);
					height_right_subtree = this->_get_height_subtree(unbalanced_node->left->right);
					if (height_left_subtree < height_right_subtree)
					{
						_balance_node(unbalanced_node, unbalanced_node->left, unbalanced_node->left->right, LEFT_RIGHT);
					}
					else
					{
						_balance_node(unbalanced_node, unbalanced_node->left, NULL, LEFT_LEFT);
					}
				}
			}
		}

		void	_check_balance_after_insertion(node* inserted_node)
		{
			int					balance_factor;
			node* 				child = NULL;
			node* 				grandchild = NULL;
			node*				unbalanced_node = NULL;
			t_type_of_unbalance	type_of_unbalance;

			for (node* temp = inserted_node; temp; temp = temp->parent)
			{
				balance_factor = this->_get_balance_factor(temp);
				if (balance_factor < -1 || balance_factor > 1)
				{
					unbalanced_node = temp;
					type_of_unbalance = this->_get_type_of_unbalance(unbalanced_node, child, grandchild);
					this->_balance_node(unbalanced_node, child, grandchild, type_of_unbalance);
					return ;
				}
				if (child != NULL)
				{
					grandchild = child;
				}
				child = temp;
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

}	// end of namespace ft

#endif
