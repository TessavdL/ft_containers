/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_avl.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 11:06:41 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/14 00:27:58 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Node.hpp"
#include <ctime>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <map>

typedef enum e_type_of_unbalance
{
	LEFT_LEFT = 0,
	LEFT_RIGHT = 1,
	RIGHT_LEFT = 2,
	RIGHT_RIGHT = 3,
}	t_type_of_unbalance;

t_type_of_unbalance	get_type_of_unbalance(Node<std::pair<int, int> >* unbalanced_node, Node<std::pair<int, int> >* child, Node<std::pair<int, int> >* grandchild)
{
	if (child == unbalanced_node->left && grandchild == child->left)
	{
		// std::cout << "LL unbalance" << std::endl;
		return (LEFT_LEFT);
	}
	else if (child == unbalanced_node->left && grandchild == child->right)
	{
		// std::cout << "LR unbalance" << std::endl;
		return (LEFT_RIGHT);
	}
	else if (child == unbalanced_node->right && grandchild == child->left)
	{
		// std::cout << "RL unbalance" << std::endl;
		return (RIGHT_LEFT);
	}
	else // child == unbalanced_node->right && grandchild == child->right
	{
		// std::cout << "RR unbalance" << std::endl;
		return (RIGHT_RIGHT);
	}
}

void	left_rotation(Node<std::pair<int, int> >* pivot, Node<std::pair<int, int> >* child, Node<std::pair<int, int> >** root)
{
	if (pivot->parent == nullptr)
	{
		*root = child;
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

void	right_rotation(Node<std::pair<int, int> >* pivot, Node<std::pair<int, int> >* child, Node<std::pair<int, int> >** root)
{
	if (pivot->parent == nullptr)
	{
		*root = child;
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

int	get_height_subtree(Node<std::pair<int, int> >* node)
{
	if (node == nullptr)
	{
		return (0);
	}

	int	height_left_subtree = get_height_subtree(node->left);
	int	height_right_subtree = get_height_subtree(node->right);

	if (height_left_subtree > height_right_subtree)
	{
		return (height_left_subtree + 1);
	}
	else
	{
		return (height_right_subtree + 1);
	}
}

bool	check_if_node_is_balanced(Node<std::pair<int, int> >* node)
{
	int	balance_factor;
	int	left;
	int	right;

	left = get_height_subtree(node->left);
	right = get_height_subtree(node->right);
	// std::cout << "left = " << left << "\tright = " << right << std::endl;
	balance_factor = left - right;
	// std::cout << "balance factor = " << balance_factor << std::endl;
	if (balance_factor > 1 || balance_factor < -1)
	{
		return (false);
	}
	else // -1 0 1 means the node is balacned
	{
		return (true);
	}
}

void	perform_balacing(Node<std::pair<int, int> >* unbalanced_node, Node<std::pair<int, int> >* child, Node<std::pair<int, int> >* grandchild, Node<std::pair<int, int> >** root, t_type_of_unbalance type_of_unbalance)
{
	// std::cout << "type = " << type << std::endl;
	
	switch (type_of_unbalance)
	{
		case LEFT_LEFT:
		{
			// std::cout << "perform right rotation" << std::endl;
			// std::cout << "unbalanced_node = " << (*(*unbalanced_node)).first << std::endl;
			// std::cout << "child node = " << (*(*child)).first << std::endl;
			right_rotation(unbalanced_node, child, root);
			break ;
		}	
		case LEFT_RIGHT:
		{
			left_rotation(child, grandchild, root);
			right_rotation(unbalanced_node, grandchild, root);
			break ;
		}
		case RIGHT_LEFT:
		{
			right_rotation(child, grandchild, root);
			left_rotation(unbalanced_node, grandchild, root);
			break ;
		}
		case RIGHT_RIGHT:
		{
			// std::cout << "perform left rotation" << std::endl;
			// std::cout << "unbalanced_node = " << (*(*unbalanced_node)).first << std::endl;
			// std::cout << "child node = " << (*(*child)).first << std::endl;
			left_rotation(unbalanced_node, child, root);
			break ;
		}
		default:
		{
			break;
		}
	}
}

bool	check_subtree_balance(Node<std::pair<int, int> >* inserted_node, Node<std::pair<int, int> >** root)
{
	Node<std::pair<int, int> >*	temp = inserted_node;
	Node<std::pair<int, int> >* child = nullptr;
	Node<std::pair<int, int> >* grandchild = nullptr;
	Node<std::pair<int, int> >*	unbalanced_node = nullptr;
	size_t						i = 0;
	t_type_of_unbalance			type_of_unbalance;

	while (temp)
	{
		if (check_if_node_is_balanced(temp) == false)
		{
			unbalanced_node = temp;
			type_of_unbalance = get_type_of_unbalance(unbalanced_node, child, grandchild);
			perform_balacing(unbalanced_node, child, grandchild, root, type_of_unbalance);
			return (false);
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
	return (true);
}

Node<std::pair<int, int> >*	create_node(Node<std::pair<int, int> >* parent, std::pair<int, int> pair, std::string side)
{
	std::allocator<Node<std::pair<int, int> > >	alloc;
	Node<std::pair<int, int> >*					new_node = alloc.allocate(1);

	std::cout << "allocation done " << std::endl;
	alloc.construct(new_node, Node<std::pair<int, int> >(parent, pair));
	std::cout << "placed " << (*(*new_node)).first << " " << side << " of " << (*(*parent)).first << std::endl;
	return (new_node);
}

Node<std::pair<int, int> >*	insert(Node<std::pair<int, int> >* root, std::pair<int, int> pair)
{
	Node<std::pair<int, int> >*	temp = root;

	// if (pair.first == (*(*temp)).first)
	// {
	// 	return (nullptr);
	// }
	if (pair.first < (*(*temp)).first)
	{
		std::cout << pair.first << " is smaller than " << (*(*temp)).first << std::endl;
		if (temp->has_left() == false)
		{
			root->left = create_node(root, pair, "left");
			return (root->left);
		}
		else
		{
			std::cout << "move to the left" << std::endl;
			return (insert(root->left, pair));
		}
	}
	else if (pair.first > (*(*temp)).first)
	{
		std::cout << pair.first << " is bigger than " << (*(*temp)).first << std::endl;
		if (temp->has_right() == false) 
		{
			root->right = create_node(root, pair, "right");
			return (root->right);
		}
		else
		{
			std::cout << "move to the right" << std::endl;
			return (insert(root->right, pair));
		}
	}
	else // pair.first == (*(*temp)).first
	{
		return (nullptr);
	}
}

Node<std::pair<int, int>>*	most_right(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;
	
	if (!root)
	{
		return (nullptr);
	}
	while (temp->right)
	{
		temp = temp->right;
	}
	return (temp);
}

Node<std::pair<int, int>>*	most_left(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;
	
	if (!root)
	{
		return (nullptr);
	}
	while (temp->left)
	{
		temp = temp->left;
	}
	return (temp);
}

Node<std::pair<int, int>>*	next(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;

	// std::cout << (*(*temp)).first << std::endl;
	if (temp->has_right()) // if the node has a right node go there and then as far left as possible
	{
		temp = temp->right;
		while (temp->has_left())
		{
			temp = temp->left;
		}
		return (temp);
	}
	else // if there is no right node go up in the tree as long as the node is on the right side of the parent
	{
		while (temp->parent->right == temp)
		{
			temp = temp->parent;
		}
		return (temp->parent);
	}
	return (nullptr); // remove?
}

int	main(void)
{
	srand(time(NULL));

	std::pair<int, int> pairs[10];
	std::vector<int> v;
	while (v.size() < 10)
	{
		int r = rand() % 20;
		if (!(std::find(v.begin(), v.end(), r) != v.end()))
		{
			v.push_back(r);
		}
	}

	std::vector<int> sortedv = v;
	std::sort(sortedv.begin(), sortedv.end());
	for (size_t i = 0; i < 10; i++)
	{
		pairs[i].first = v[i];
		pairs[i].second = v[i];
		std::cout << pairs[i].first << "\t";
	}
	std::cout << std::endl << std::endl;
	std::allocator<Node<std::pair<int, int> > > alloc;
	
	Node<std::pair<int, int> >*	root;
	Node<std::pair<int, int> >*	inserted_node;
	root = alloc.allocate(1);
	alloc.construct(root, Node<std::pair<int, int> >(pairs[0]));
	std::cout << "created root with value " << pairs[0].first << std::endl << std::endl;

	for (size_t i = 1; i < 10; i++)
	{
		inserted_node = insert(root, pairs[i]);
		// std::cout << "value = " << (*(*inserted_node)).first << std::endl;
		if (check_subtree_balance(inserted_node, &root) == true)
		{
			std::cout << "tree is balanced"  << std::endl << std::endl;
		}
		else
		{
			std::cout << "tree needs to be balanced"  << std::endl << std::endl;
		}
		inserted_node = nullptr;
	}

	Node<std::pair<int, int>>*	begin = most_left(root);
	Node<std::pair<int, int>>*	end = most_right(root);
	std::cout << "root\t= " << (*(*root)).first << std::endl;
	std::cout << "begin\t= " << (*(*begin)).first << std::endl;
	std::cout << "end\t= " << (*(*end)).first << std::endl << std::endl;

	std::vector<int> save;

	while (begin != end)
	{
		save.push_back((*(*begin)).first);
		begin = next(begin);
	}
	save.push_back((*(*end)).first);
	for (std::vector<int>::iterator it = save.begin(); it != save.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl;


	std::map<int, int> mapp;
	std::map<int, int>::iterator it;

	mapp.insert({1, 2});
	it = mapp.begin();
	std::cout << "*it will return the pair and you can access it through first and second" << std::endl;
	std::cout << (*it).first << " " << (*it).second << std::endl;
	std::cout << "it->first will return the key and it->second will return the value" << std::endl;
	std::cout << it->first << " " << it->second << std::endl;
	// std::cout << "at works based on the key and returns the value of the pair" << std::endl;
	// std::cout << mapp.at(1) << std::endl;
	std::cout << "[] on an existing key returns the value of the pair" << std::endl;
	std::cout << mapp[1] << std::endl;
	std::cout << "size = " << mapp.size() << std::endl;
	std::cout << "[] with nonexisting key inserts a new element with that key and returns a referense to the value" << std::endl;
	std::cout << "if you don't give a value, the default constructor of the value is called" << std::endl;
	mapp[20];
	std::cout << mapp[20] << std::endl;
	std::cout << "size = " << mapp.size() << std::endl;
	mapp[20]=30;
	std::cout << mapp[20] << std::endl;
	mapp[300]=400;
	std::cout << mapp[300] << std::endl;
	std::cout << "size = " << mapp.size() << std::endl;
	std::cout << "if a new element is inserted and allocator cannot construct an elemant with k and a default-constructed mapped type (or if mapped t ype is not default constructible) -> undifined behavior" << std::endl;
}
