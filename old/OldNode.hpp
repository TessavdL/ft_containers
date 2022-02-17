/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OldNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 11:54:42 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/15 11:54:45 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later
# include <utility>		// for std::pair, should include own pair later
# include <memory>		// for std::allocator

template <class Pair = std::pair<class Key, class T>, class Compare = std::less<Key> >
class Node
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef Pair	value_type;
		typedef Compare	key_compare;
		typedef Key		key_type;
		typedef T		mapped_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~
		Node*	left;
		Node*	parent;
		Node*	right;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		Node(void)
		{
			this->left = nullptr;
			this->parent = nullptr;
			this->right = nullptr;
			// std::cout << "Default constructor" << std::endl;
			return ;
		}
		Node(const value_type& val)
		{
			this->_data = val;
			this->left = nullptr;
			this->parent = nullptr;
			this->right = nullptr;
			std::cout << "Parameter constructor" << std::endl;
			return ;
		}
		Node(Node* p, const value_type& val)
		{
			this->_data = val;
			this->left = nullptr;
			this->parent = p;
			this->right = nullptr;
			std::cout << "Parameter constructor parent" << std::endl;
			return ;
		}
		Node(const Node& other)
		{
			*this = other;
			std::cout << "Copy constructor" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~Node(void)
		{
			return ;
		}

		// -------------------------ASSIGNMENT OPERATOR-------------------------
		Node&	operator=(const Node& other)
		{
			if (this != &other)
			{
				this->_data = other._data;
				this->left = other.left;
				this->parent = other.parent;
				this->right = other.right;
			}
			std::cout << "Assigment operator" << std::endl;
			return (*this);
		}

		value_type&	operator*(void)
		{
			return(this->_data);
		}

		// --------------------------UTILITY FUNCTIONS--------------------------
		bool	has_left(void)
		{
			if (this->left)
				return (true);
			return (false);
		}

		bool	has_right(void)
		{
			if (this->right)
				return (true);
			return (false);
		}

		bool	has_parent(void)
		{
			if (this->parent)
				return (true);
			return (false);
		}

		void	set_data(Node<value_type>* node)
		{
			this->_data = *(*node);
		}

		private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type	_data;
};

#endif

/*
if key < n_key
if left n = n_left
if right n = n_right
n = n_parent
if !n_parent not found

if key > n_key
if right n = n_right
if left n = n_left
n = n_parent
if !n_parent not found

if key == n_key
return
*/