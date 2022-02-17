/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TestClass.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 19:25:38 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/12 17:02:40 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include <iostream>
# include <cstddef>

# include "../includes/RandomAccessIterator.hpp"
# include "../includes/BidirectionalIterator.hpp"

template <typename T>
class TestClass
{
	public:
	typedef BidirectionalIterator<T> iterator;

		TestClass(int n) : size(n), TestArray(nullptr)
		{
			if (size > 0)
				this->TestArray = new T[size];
			std::cout << "Constructor of TestClass called" << std::endl;
			return ;
		}
		~TestClass(void)
		{
			delete [] this->TestArray;
			std::cout << "Destructor of TestClass called" << std::endl;
			return ;
		}
		void	SetArray(T const& value)
		{
			for (std::ptrdiff_t i = 0; i < 5; i++)
				this->TestArray[i] = i;
		}
		T&	operator[](std::ptrdiff_t index)
		{
			return (TestArray[index]);
		}
		iterator	begin(void)
		{
			iterator	it(TestArray);
			
			return (it);
		}
		iterator	end(void)
		{
			iterator	it(TestArray + size);

			return (it);
		}
		T*	TestArray;
		int	size;
};

# endif
