/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_avl.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 11:06:41 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/04 16:07:34 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Node.hpp"
#include <ctime>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>

int	get_height_subtree(Node<std::pair<int, int> >* node)
{
	if (node == nullptr)
	{
		return (0);
	}

	int	height_left_subtree = get_height_subtree(node->left);
	int	height_right_subtree = get_height_subtree(node->right);
	
	// std::cout << "left = " << height_left_subtree << "\tright = " << height_right_subtree << std::endl;

	if (height_left_subtree > height_right_subtree)
	{
		return (height_left_subtree + 1);
	}
	else
	{
		return (height_right_subtree + 1);
	}
}

int	get_balance_factor(Node<std::pair<int, int> >* node)
{
	int	balance_factor;
	int	left;
	int	right;

	left = get_height_subtree(node->left);
	right = get_height_subtree(node->right);
	// std::cout << "left = " << left << "\tright = " << right << std::endl;
	balance_factor = left - right;
	return (balance_factor);
}

bool	check_subtree_balance(Node<std::pair<int, int> >* inserted_node, Node<std::pair<int, int> >* root)
{
	Node<std::pair<int, int> >* temp = inserted_node;
	// Node<std::pair<int, int> >* node_to_be_balanced;
	int	balance_factor;

	// std::cout << "value\t= " << (*(*temp)).first << std::endl;

	while (temp != root)
	{
		balance_factor = get_balance_factor(temp);
		// std::cout << "balance factor = " << balance_factor << std::endl;
		if (balance_factor < -1 || balance_factor > 1)
			// node_to_be_balanced = temp;
		{
			return (false);
		}
		temp = temp->parent;
	}
	return (true);	
}

Node<std::pair<int, int> >*	create_node(Node<std::pair<int, int> >* parent, std::pair<int, int> pair, std::string side)
{
	std::allocator<Node<std::pair<int, int> > > alloc;
	Node<std::pair<int, int> >*	new_node;

	new_node = alloc.allocate(1);
	alloc.construct(new_node, Node<std::pair<int, int> >(parent, pair));
	std::cout << "placed node " << side << std::endl << std::endl;
	return (new_node);
}

Node<std::pair<int, int> >*	insert(Node<std::pair<int, int> >* root, std::pair<int, int> pair)
{
	Node<std::pair<int, int> >*	temp = root;

	if (pair.first == (*(*temp)).first)
	{
		return (nullptr);
	}
	if (pair.first < (*(*temp)).first)
	{
		// std::cout << pair.first << " is smaller than " << (*(*temp)).first << std::endl;
		if (temp->has_left() == false)
		{
			root->left = create_node(root, pair, "left");
			return (root->left);
		}
		else
		{
			// std::cout << "move to the left" << std::endl;
			return (insert(root->left, pair));
		}
	}
	else if (pair.first > (*(*temp)).first)
	{
		// std::cout << pair.first << " is bigger than " << (*(*temp)).first << std::endl;
		if (temp->has_right() == false) 
		{
			root->right = create_node(root, pair, "right");
			return (root->right);
		}
		else
		{
			// std::cout << "move to the right" << std::endl;
			return (insert(root->right, pair));
		}
	}
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
	std::cout << "created root" << std::endl << std::endl;

	for (size_t i = 1; i < 10; i++)
	{
		inserted_node = insert(root, pairs[i]);
		std::cout << "value = " << 
		if (check_subtree_balance(inserted_node, root) == true)
		{
			std::cout << "tree is balanced"  << std::endl;
		}
		else
		{
			std::cout << "tree is NOT balanced"  << std::endl;
		}
		inserted_node = nullptr;
	}
}
