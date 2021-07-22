/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 20:21:49 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/07/20 13:30:54 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vector.hpp"
# include <iostream>
# include <vector>

//max size is the theoretical maximum number of elements that could be put in your vector
//max size depends on your system (32-bit/64-bit) and the data type
//2 ^ (native_pointer_bitwidth) / sizeof(dataType) - 1

//capacity returns the number of elements that the container has currently allocated space for
//capacity integer doubles the amount of allocated space every time it has to allocate new memory
void	vector_integers_capacity(void)
{
	std::vector<int>	Vector_int;

	for (int i = 0; i < 500; i++)
	{
		Vector_int.push_back(i);
		std::cout << "i = " << i << "\tcapacity =" << Vector_int.capacity() << std::endl;
	}
}

//capacity chars doubles the amount of allocated space every time it has to allocate new memory
void	vector_chars_capacity(void)
{
	std::vector<char>	Vector_char;

	for (int i = 0; i < 500; i++)
	{
		Vector_char.push_back('a');
		std::cout << "i = " << i << "\tcapacity =" << Vector_char.capacity() << std::endl;
	}
	std::cout << "capacity before shrink to fit = " << Vector_char.capacity() << std::endl;
	Vector_char.shrink_to_fit();
	std::cout << "capacity after shrink to fit = " << Vector_char.capacity() << std::endl;
}

//empty returns a boolean, if the vector is empty it returns true else it returns false
//after clear the size is 0 and therefore empty returns true
void	vector_integers_empty(void)
{
	std::vector<int>	Vector_int {0};

	std::cout << "size = " << Vector_int.size() << std::endl;
	std::cout << "is empty = " << std::boolalpha << Vector_int.empty() << std::endl;
	std::cout << "clearing vector..." << std::endl;
	Vector_int.clear();
	std::cout << "size = " << Vector_int.size() << std::endl;
	std::cout << "is empty = " << std::boolalpha << Vector_int.empty() << std::endl;
}

int	main(void)
{
	// vector_integers_empty();
	// vector_integers_capacity();
	// vector_chars_capacity();
	Vector<int>			mine_default;
	Vector<int>			mine_fill(40, 100);
	Vector<int>			mini_fill_copy(mine_fill);
	std::vector<int>	original_default;

	std::cout << "mine max_size =\t\t" << mine_default.max_size() << std::endl;
	std::cout << "original max_size =\t" << original_default.max_size() << std::endl;
	return (0);
}
