/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_vector.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 20:21:49 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/19 17:02:45 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Vector.hpp"
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

void	vector_element_access(void)
{
	std::vector<int>	original_default;
	ft::vector<int>			mine_default;

	std::cout << "original capapcity " << original_default.capacity() << std::endl;
	std::cout << "mine capapcity " << mine_default.capacity() << std::endl;

	original_default.reserve(50);
	mine_default.reserve(50);

	std::cout << "original capapcity " << original_default.capacity() << std::endl;
	std::cout << "mine capapcity " << mine_default.capacity() << std::endl;

	std::vector<int>	original_fill(20, 42);
	ft::vector<int>			mine_fill(20, 42);

	for (std::vector<int>::iterator it = original_fill.begin(); it != original_fill.end(); it++)
		std::cout << "original " << *it << std::endl;
	for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++)
		std::cout << "mine " << *it << std::endl;

	original_fill.reserve(50);
	std::cout << "CURRENT CAPACITY " << mine_fill.capacity() << std::endl;
	mine_fill.reserve(50);

	for (std::vector<int>::iterator it = original_fill.begin(); it != original_fill.end(); it++)
		std::cout << "original " << *it << std::endl;
	for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++)
		std::cout << "mine " << *it << std::endl;

	original_fill[0] = 0;
	std::cout << *(original_fill.data()) << std::endl;
	mine_fill[0] = 0;
	std::cout << *(mine_fill.data()) << std::endl;

	original_fill.front() = 1;
	std::cout << original_fill.front() << std::endl;
	mine_fill.front() = 1;
	std::cout << mine_fill.front() << std::endl;

	original_fill.back() = 2;
	std::cout << original_fill.back() << std::endl;
	std::vector<int>::iterator original_back = original_fill.end();
	original_back--;
	std::cout << *original_back << std::endl;
	mine_fill.back() = 2;
	std::cout << mine_fill.back() << std::endl;
	ft::vector<int>::iterator mine_back = mine_fill.end();
	mine_back--;
	std::cout << *mine_back << std::endl;
}

void	vector_clear(void)
{
	std::vector<int>	original_fill(20, 42);
	ft::vector<int>			mine_fill(20, 42);

	original_fill.push_back(21);
	mine_fill.push_back(21);

	std::cout << "original size\t" << original_fill.size() << std::endl;
	std::cout << "mine size\t" << mine_fill.size() << std::endl;
	std::cout << "original back\t" << original_fill.back() << std::endl;
	std::cout << "mine back\t" << mine_fill.back() << std::endl;

	original_fill.pop_back();
	mine_fill.pop_back();

	std::cout << "original size\t" << original_fill.size() << std::endl;
	std::cout << "mine size\t" << mine_fill.size() << std::endl;
	std::cout << "original back\t" << original_fill.back() << std::endl;
	std::cout << "mine back\t" << mine_fill.back() << std::endl;
	std::cout << "original[20]\t" << original_fill[20] << std::endl;
	std::cout << "mine\t[20]\t" << mine_fill[20] << std::endl;

	int original = original_fill[20];
	std::cout << original << std::endl;
	int mine = mine_fill[20];
	std::cout << mine << std::endl;

	original_fill.clear();
	mine_fill.clear();

	std::cout << "original capapcity\t" << original_fill.capacity() << std::endl;
	std::cout << "mine capapcity\t\t" << mine_fill.capacity() << std::endl;
	std::cout << "original size\t\t" << original_fill.size() << std::endl;
	std::cout << "mine size\t\t" << mine_fill.size() << std::endl;
	std::cout << "original [0]\t\t" << original_fill[0] << std::endl;
	std::cout << "mine [0]\t\t" << mine_fill[0] << std::endl;
}

void	vector_erase(void)
{
	std::vector<int>	original_fill(20);
	ft::vector<int>			mine_fill(20);

	for (size_t i = 0; i < original_fill.size(); i++)
		original_fill[i] = i;
	for (size_t i = 0; i < mine_fill.size(); i++)
		mine_fill[i] = i;

	std::cout << "original\t\t";
	for (std::vector<int>::iterator it = original_fill.begin(); it != original_fill.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "mine\t\t\t";
	for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
		
	int even = 0;
	for (std::vector<int>::iterator it = original_fill.begin(); it != original_fill.end(); it++, even++)
	{
		if (even % 2 != 0)
		{
			original_fill.erase(it);
			it--;
		}
	}
	even = 0;
	for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++, even++)
	{
		if (even % 2 != 0)
		{
			mine_fill.erase(it);
			it--;
		}
	}

	std::cout << "original after erase\t";
	for (std::vector<int>::iterator it = original_fill.begin(); it != original_fill.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "original did it remove?\t";
	for (size_t i = 0; i < original_fill.capacity(); i++)
		std::cout << original_fill[i] << "\t";
	std::cout << std::endl;
	std::cout << "mine after erase\t";
	for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "mine did it remove?\t";
	for (size_t i = 0; i < mine_fill.capacity(); i++)
		std::cout << mine_fill[i] << "\t";
	std::cout << std::endl;

	std::vector<int>	original(20);
	ft::vector<int>	mine(20);

	for (size_t i = 0; i < original.size(); i++)
		original[i] = i;
	for (size_t i = 0; i < mine.size(); i++)
		mine[i] = i;

	std::vector<int>::iterator toerase = original.begin() + 10;

	original.erase(toerase, original.end() - 1);
	std::cout << "original half erase\t";
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	ft::vector<int>::iterator toerase2 = mine.begin() + 10;

	mine.erase(toerase2, mine.end() - 1);
	std::cout << "mine half erase\t\t";
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

void	vector_resize(void)
{
	std::vector<int>	original(10);
	ft::vector<int>			mine(10);

	std::cout << original.size() << std::endl;
	for (size_t i = 0; i < 10; i++)
		original[i] = i;
	for (size_t i = 0; i < 10; i++)
		mine[i] = i;
	
	std::cout << "original\t\t";
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << "mine\t\t\t";
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	original.resize(25, 1);
	std::cout << "original capacity is now " << original.capacity() << std::endl;
	std::cout << "original size is now " << original.size() << std::endl;
	std::cout << "original\t\t";
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "original did it remove?\t";
	for (size_t i = 0; i < original.capacity(); i++)
		std::cout << original[i] << "\t";
	std::cout << std::endl;

	mine.resize(25, 1);
	std::cout << "mine capacity is now " << mine.capacity() << std::endl;
	std::cout << "mine size is now " << mine.size() << std::endl;
	std::cout << "mine\t\t\t";
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "mine did it remove?\t";
	for (size_t i = 0; i < mine.capacity(); i++)
		std::cout << mine[i] << "\t";
	std::cout << std::endl;

	original.resize(30);
	std::cout << "original capacity is now " << original.capacity() << std::endl;
	std::cout << "original size is now " << original.size() << std::endl;
	std::cout << "original\t\t";
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "original did it remove?\t";
	for (size_t i = 0; i < original.capacity(); i++)
		std::cout << original[i] << "\t";
	std::cout << std::endl;

	mine.resize(30);
	std::cout << "mine capacity is now " << mine.capacity() << std::endl;
	std::cout << "mine size is now " << mine.size() << std::endl;
	std::cout << "mine\t\t\t";
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "mine did it remove?\t";
	for (size_t i = 0; i < mine.capacity(); i++)
		std::cout << mine[i] << "\t";
	std::cout << std::endl;
}

void	vector_swap(void)
{
	std::vector<int>	one{1, 2, 3};
	std::vector<int>	two{4, 5};

	std::cout << "one\t\t\t";
	for (std::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "two\t\t\t";
	for (std::vector<int>::iterator it = two.begin(); it != two.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	one.swap(two);
	std::cout << "one\t\t\t";
	for (std::vector<int>::iterator it = one.begin(); it != one.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "two\t\t\t";
	for (std::vector<int>::iterator it = two.begin(); it != two.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	ft::vector<int>	een(3);
	ft::vector<int>	twee(2);
	een[0] = 1;
	een[1] = 2;
	een[2] = 3;
	twee[0] = 4;
	twee[1] = 5;

	std::cout << "een\t\t\t";
	for (ft::vector<int>::iterator it = een.begin(); it != een.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "twee\t\t\t";
	for (ft::vector<int>::iterator it = twee.begin(); it != twee.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	een.swap(twee);
	std::cout << "een\t\t\t";
	for (ft::vector<int>::iterator it = een.begin(); it != een.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	std::cout << "twee\t\t\t";
	for (ft::vector<int>::iterator it = twee.begin(); it != twee.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

void	vector_insert(void)
{
	std::vector<int>	original(10, 42);
	std::vector<int>	original_empty;
	std::vector<int>	original_out_of_range(5, 21);
 
 	// if you try to insert at a pos that is not in the vector range it segfaults
	// std::vector<int>::iterator it = original_out_of_range.begin();
	// original.insert(it, 3);

	// you can insert into an empty vector
	std::vector<int>::iterator	it2 = original_empty.begin();
	original_empty.insert(it2, 21);
	std::cout << "proof you can insert into an empty vector " << *original_empty.begin() << std::endl << std::endl;

	std::cout << "If the range iterators are the same, nothing is inserted and the capacity remains the same" << std::endl;
	std::vector<int>::iterator	it3 = original.begin();
	std::cout << "capacity " << original.capacity() << std::endl;
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
	original.insert(original.end(), 3, 21);
	std::cout << "capacity " << original.capacity() << std::endl;
	for (std::vector<int>::iterator it = original.begin(); it != original.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	ft::vector<int>	mine(10);
	for (size_t i = 0; i < 10; i++)
		mine[i] = i;
	mine.insert(mine.begin() + 1, 21);
	std::cout << "capacity " << mine.capacity() << std::endl;
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	ft::vector<int>	fill(10);
	for (size_t i = 0; i < 10; i++)
		fill[i] = i;
	fill.insert(fill.begin(), (size_t)3, 21);
	std::cout << "capacity " << fill.capacity() << std::endl;
	for (ft::vector<int>::iterator it = fill.begin(); it != fill.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

#include "../includes/InputIterator.hpp"

void	vector_inputiterator(void)
{
	ft::vector<int>	mine;

	mine.insert(mine.begin(), 1);
	mine.insert(mine.begin(), 2);
	mine.insert(mine.begin(), 3);

	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	InputIterator<int>	begin = mine.begin();
	InputIterator<int>	end = mine.end();

	ft::vector<int>		mine2(begin, end);

}

int	main(void)
{
	// vector_integers_empty();
	// vector_integers_capacity();
	// vector_chars_capacity();
	// ft::vector<int>			mine_default;
	// ft::vector<int>			mine_fill(5, 2);
	// ft::vector<int>			mini_fill_copy(mine_fill);
	// std::vector<int>	original_default;
	// std::vector<int>	original_fill(5, 3);

	// std::cout << "mine max_size =\t\t" << mine_default.max_size() << std::endl;
	// std::cout << "original max_size =\t" << original_default.max_size() << std::endl;
	// for (int i = 0; i < 5; i++)
	// 	std::cout << original_fill[i] << std::endl;
	// for (ft::vector<int>::iterator it = mine_fill.begin(); it != mine_fill.end(); it++)
	// 	std::cout << "iterator " << *it << std::endl;
	// for (ft::vector<int>::iterator it = mine_default.begin(); it != mine_default.end(); it++)
	// 	std::cout << "mine default " << *it << std::endl;
	// for (std::vector<int>::iterator it = original_default.begin(); it != original_default.end(); it++)
	// 	std::cout << "original default " << *it << std::endl;

	// vector_element_access();
	// vector_clear();
	// vector_erase();
	// vector_resize();
	// vector_swap();
	// vector_insert();
	vector_inputiterator();
	return (0);
}
