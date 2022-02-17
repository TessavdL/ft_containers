/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 16:45:32 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/24 13:54:43 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft {

template <class T>
class node
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T			value_type;
		typedef value_type*	pointer;
		typedef value_type&	reference;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~
		node*	left;
		node*	parent;
		node*	right;
		pointer	data;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		node(void) : left(NULL), parent(NULL), right(NULL), data(NULL) {}

		node(pointer ptr) : left(NULL), parent(NULL), right(NULL), data(ptr) {}

		node(node* p, pointer ptr) : left(NULL), parent(p), right(NULL), data(ptr) {}

		node(const node& other) : left(other.left), parent(other.parent), right(other.right), data(other.data) {}

		// -----------------------------DESTRUCTOR------------------------------
		~node(void) {}

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
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		pointer	operator->(void)
		{
			return (this->data);
		}

		reference operator*(void)
		{
			return (*this->data);
		}

		// --------------------------NEXT AND PREVIOUS--------------------------
		node*	next(void)
		{
			node*	temp = this;
	
			if (temp->right)
			{
				if (temp->right->data == NULL)
				{
					return (NULL);
				}
				temp = temp->right;
				while (temp && temp->left)
				{
					temp = temp->left;
				}
			}
			else
			{
				while (temp->parent && temp->parent->right == temp)
				{
					temp = temp->parent;
				}
				temp = temp->parent;
			}
			return (temp);
		}

		node*	previous(void)
		{
			node*	temp = this;

			if (temp->left)
			{
				if (temp->left->data == NULL)
				{
					return (NULL);
				}
				temp = temp->left;
				while (temp && temp->right)
				{
					temp = temp->right;
				}
			}
			else
			{
				while (temp && temp->parent->left == temp)
				{
					temp = temp->parent;
				}
				temp = temp->parent;
			}
			return (temp);
		}
};

}	// end of namespace ft

#endif
