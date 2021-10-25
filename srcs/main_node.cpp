/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_node.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/22 19:00:43 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/25 15:04:23 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Node.hpp"
#include <ctime>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>

Node<std::pair<int, int>>* find(Node<std::pair<int, int>>* root, int key)
{
	if (key < (*(*root)).first)
	{
		if (root->left)
			return (find(root->left, key));
		else
			return (NULL);
	}
	else if (key > (*(*root)).first)
	{
		if (root->right)
			return (find(root->right, key));
		else
			return (NULL);
	}
	else // key == node_key
		return (root);
}

void	erase_node(Node<std::pair<int, int>>** root, Node<std::pair<int, int>>* node_to_delete)
{
	std::allocator<Node<std::pair<int, int>>> alloc;
	Node<std::pair<int, int>>* temp = node_to_delete;

	if (!node_to_delete->has_left() && !node_to_delete->has_right())
	{
		if (node_to_delete == *root)
		{
			*root = NULL;
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
		alloc.destroy(node_to_delete);
		alloc.deallocate(node_to_delete, 1);
	}
	else if (node_to_delete->has_left() && !node_to_delete->has_right())
	{
		if (node_to_delete == *root)
		{
			*root = temp->left;
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
		alloc.destroy(node_to_delete);
		alloc.deallocate(node_to_delete, 1);
	}
	else if (!node_to_delete->has_left() && node_to_delete->has_right())
	{
		if (node_to_delete == *root)
		{
			*root = temp->right;
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
		alloc.destroy(node_to_delete);
		alloc.deallocate(node_to_delete, 1);
	}
	else if (node_to_delete->has_left() && node_to_delete->has_right())
	{
		temp = temp->right;
		while (temp->left)
			temp = temp->left;
		node_to_delete->set_data(temp);
		erase_node(root, temp);
	}
}

Node<std::pair<int, int>>*	next(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;

	// std::cout << (*(*temp)).first << std::endl;
	if (temp->has_right())
	{
		temp = temp->right;
		while (temp->has_left())
		{
			temp = temp->left;
		}
		return (temp);
	}
	else
	{
		while (temp->parent->right == temp)
		{
			temp = temp->parent;
		}
		return (temp->parent);
	}
	return (NULL);
}

Node<std::pair<int, int>>*	previous(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;

	if (temp->has_left())
	{
		temp = temp->left;
		while (temp->has_right())
		{
			temp = temp->right;
		}
		return (temp);
	}
	else
	{
		while (temp->parent->left == temp)
		{
			temp = temp->parent;
		}
		return (temp->parent);
	}
	return (NULL);
}

Node<std::pair<int, int>>*	most_right(Node<std::pair<int, int>>* root)
{
	Node<std::pair<int, int>>*	temp = root;
	
	if (!root)
	{
		return (NULL);
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
		return (NULL);
	}
	while (temp->left)
	{
		temp = temp->left;
	}
	return (temp);
}

Node<std::pair<int, int>>*	create_node(Node<std::pair<int, int>>* parent, std::pair<int, int> pair, std::string side)
{
	std::allocator<Node<std::pair<int, int>>> alloc;
	Node<std::pair<int, int>>*	new_node;

	new_node = alloc.allocate(1);
	alloc.construct(new_node, Node<std::pair<int, int>>(parent, pair));
	std::cout << "placed node " << side << std::endl << std::endl;
	return (new_node);
}

void	insert(Node<std::pair<int, int>>* root, std::pair<int, int> pair)
{
	Node<std::pair<int, int>>*	temp = root;

	if (pair.first == (*(*temp)).first)
	{
		return ;
	}
	if (pair.first < (*(*temp)).first)
	{
	//	std::cout << pair.first << " is smaller than " << (*(*temp)).first << std::endl;
		if (temp->has_left() == false)
		{
			root->left = create_node(root, pair, "left");
		}
		else
		{
	//		std::cout << "move to the left" << std::endl;
			insert(root->left, pair);
		}
	}
	else if (pair.first > (*(*temp)).first)
	{
	//	std::cout << pair.first << " is bigger than " << (*(*temp)).first << std::endl;
		if (temp->has_right() == false) 
		{
			root->right = create_node(root, pair, "right");
		}
		else
		{
		//	std::cout << "move to the right" << std::endl;
			insert(root->right, pair);
		}
	}
}

int main(void)
{
	std::pair<int, int> pairs[10];
	srand(time(NULL));

	// std::vector<int>	v = {82, 73, 76, 72, 59, 54, 74, 12, 86, 10};

	// std::vector<int> v = {83, 86, 77, 15, 93, 35, 92, 49, 21, 62};

	// std::vector<int> v = {43,3,86,49,73,92,8,76,42,85};

	// std::vector<int> v = {0, 2, 43, 23, 1, 4, 3, 5, 7, 8}; // delete root with most left

	// std::vector<int> v = {43, 2, 1, 4, 7, 0, 23, 9, 8, 12}; // delete root with most right

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
	std::allocator<Node<std::pair<int, int>>> alloc;
	
	Node<std::pair<int, int>>*	root;
	root = alloc.allocate(1);
	alloc.construct(root, Node<std::pair<int, int>>(pairs[0]));

	for (size_t i = 1; i < 10; i++)
	{
		insert(root, pairs[i]);
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

	for (std::vector<int>::iterator it = sortedv.begin(); it != sortedv.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	for (std::vector<int>::iterator it = save.begin(); it != save.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl;

	Node<std::pair<int, int>>*	rbegin = most_right(root);
	Node<std::pair<int, int>>*	rend = most_left(root);
	std::cout << "root\t= " << (*(*root)).first << std::endl;
	std::cout << "begin\t= " << (*(*rbegin)).first << std::endl;
	std::cout << "end\t= " << (*(*rend)).first << std::endl << std::endl;

	std::vector<int> rsave;

	while (rbegin != rend)
	{
		rsave.push_back((*(*rbegin)).first);
		rbegin = previous(rbegin);
	}
	rsave.push_back((*(*rend)).first);
	
	// std::cout << (*(*rend)).first << std::endl << std::endl;

	std::reverse(sortedv.begin(), sortedv.end());
	for (std::vector<int>::iterator it = sortedv.begin(); it != sortedv.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	for (std::vector<int>::iterator it = rsave.begin(); it != rsave.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl;

	// ERASE

	erase_node(&root, (root));
	std::cout << "erased the node" << std::endl;
	Node<std::pair<int, int>>*	ebegin = most_left(root);
	Node<std::pair<int, int>>*	eend = most_right(root);
	std::cout << "root\t= " << (*(*root)).first << std::endl;
	std::cout << "begin\t= " << (*(*ebegin)).first << std::endl;
	std::cout << "end\t= " << (*(*eend)).first << std::endl << std::endl;

	std::vector<int> esave;

	while (ebegin != eend)
	{
		esave.push_back((*(*ebegin)).first);
		ebegin = next(ebegin);
	}
	esave.push_back((*(*eend)).first);
	for (std::vector<int>::iterator it = esave.begin(); it != esave.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl << std::endl;

	// FIND

	if (find(root, 1))
		std::cout << "found it!" << std::endl;
	else
		std::cout << "couldn't find it" << std::endl;

	// CLEAR

	while (root != NULL)
	{
		erase_node(&root, (root));
	}
	if (root == NULL)
		std::cout << "empty" << std::endl;
	return (0);
}
