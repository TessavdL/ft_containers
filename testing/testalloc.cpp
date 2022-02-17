/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testalloc.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 16:45:35 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/12 23:14:07 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

int	main(void)
{
	std::allocator<int>	TestAlloc;

	int*	IntArray = TestAlloc.allocate(5);

	for (int i = 0; i < 5; i++)
		std::cout << *IntArray + i << std::endl;
	std::cout << std::endl;
	TestAlloc.construct(IntArray, 100);
	for (int i = 0; i < 5; i++)
		std::cout << *IntArray + i << std::endl;
	std::cout << std::endl;
	TestAlloc.destroy(IntArray);
	for (int i = 0; i < 5; i++)
		std::cout << *IntArray + i << std::endl;
	TestAlloc.deallocate(IntArray, 5);
	
	// allocator for string values
    std::allocator<std::string> myAllocator;
  
    // allocate space for three strings
    std::string* str = myAllocator.allocate(3);
  
    // construct these 3 strings
    myAllocator.construct(str, "Geeks");
    myAllocator.construct(str + 1, "for");
    myAllocator.construct(str + 2, "Geeks");
  
    std::cout << "1a " << str[0] << str[1] << str[2] << std::endl;

    // destroy these 3 strings
    myAllocator.destroy(str);
    myAllocator.destroy(str + 1);
    myAllocator.destroy(str + 2);
  
    myAllocator.deallocate(str, 3);
	str = myAllocator.allocate(3)
    myAllocator.construct(str, "Geeks");
    myAllocator.construct(str + 1, "for");
    myAllocator.construct(str + 2, "Geeks");

	// even though strings are destroyed you can still print them
 	std::cout << "2 "<< str[0] << str[1] << str[2] << std::endl;

    // deallocate space for 3 strings


	// trying to print the strings after deallocation is not possible
 	//  std::cout << "3 " << str[0] << str[1] << str[2] << std::endl;

	 // what happens if we construct twice without destroy
	return (0);
}
