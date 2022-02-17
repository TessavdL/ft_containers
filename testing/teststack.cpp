/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   teststack.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 17:44:51 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/27 17:56:16 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Stack.hpp"
#include <stack>
#include <vector>
#include <iostream>

void	stdstack(void)
{
	std::stack<int, std::vector<int> >	s;

	if (s.empty() == true)
	{
		std::cout << "stack is empty" << std::endl;
	}
	s.push(1);

	if (s.empty() == false)
	{
		std::cout << "stack is not empty" << std::endl;
	}
	s.push(2);
	s.push(3);

	std::cout << "size = " << s.size() << std::endl;

	std::cout << "top = " << s.top() << std::endl;

	s.pop();

	std::cout << "top = " << s.top() << std::endl;
}

void	ftstack(void)
{
	ft::stack<int>	s;

	if (s.empty() == true)
	{
		std::cout << "stack is empty" << std::endl;
	}
	s.push(1);

	if (s.empty() == false)
	{
		std::cout << "stack is not empty" << std::endl;
	}
	s.push(2);
	s.push(3);

	std::cout << "size = " << s.size() << std::endl;

	std::cout << "top = " << s.top() << std::endl;

	s.pop();

	std::cout << "top = " << s.top() << std::endl;
}

int	main(void)
{
	stdstack();
	ftstack();
	return (0);
}
