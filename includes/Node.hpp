/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/20 16:45:32 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/29 12:18:36 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>	// for output, prob remove later

# include "Pair.hpp"

namespace ft {
template<typename, typename>
class pair;
}

namespace ft {
template <class T = ft::pair<class T1, class T2> >
class node
{
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER OBJECTS~~~~~~~~~~~~~~~~~~~~~~~~~~
		node*	left;
		node*	parent;
		node*	right;
		pointer	data;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		node(void) : left(NULL), parent(NULL), right(NULL), data(NULL)
		{
			// std::cout << "Default constructor of node called" << std::endl;
		}
		node(pointer ptr) : left(NULL), parent(NULL), right(NULL), data(ptr)
		{
			// std::cout << "Parameter constructor root of node called" << std::endl;
		}
		node(node* p, pointer ptr) : left(NULL), parent(p), right(NULL), data(ptr)
		{
			// std::cout << "Parameter constructor leaf of node called" << std::endl;
		}
		node(const node& other) : left(other.left), parent(other.parent), right(other.right), data(other.data)
		{
			// std::cout << "Copy constructor of node called" << std::endl;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~node(void)
		{
			// std::cout << "Destructor of node called" << std::endl;
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
}

#endif
