/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testreverseiterator.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 22:08:50 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/18 15:38:57 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ReverseIterator.hpp"
// #include <iterator>
// #include <algorithm>
// #include <vector>
// #include <iostream>

// int main(void)
// {
// 	int i;
//    std::vector<int> vec;
//    for ( i = 1 ; i < 6 ; ++i )
//    {
//       vec.push_back ( 2 * i );
//    }

//    std::vector <int>::iterator vIter;
//    std::cout << "The vector vec is: ( ";
//    for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
//       std::cout << *vIter << " ";
//    std::cout << ")." << std::endl;

// 	ft::reverse_iterator<std::vector<int>::iterator>	rvIter(vIter);
// 	for (rvIter = vec.rbegin (); rvIter != vec.end(); rvIter++)
// 	std::cout << *rvIter << std::endl;


#include <iostream>
#include <string>
#include <iterator>
 
int main()
{
    std::string s = "Hello, world";
    ft::reverse_iterator<std::string::iterator> r = s.rbegin();
    r[7] = 'O'; // replaces 'o' with 'O' 
    r += 7; // iterator now points at 'O'
    std::string rev(r, s.rend());
    std::cout << rev << '\n';

   return (0);
}