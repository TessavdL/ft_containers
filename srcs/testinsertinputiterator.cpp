/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testinsertinputiterator.cpp                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:00:03 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/25 20:55:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "../includes/Vector.hpp"

int	main(void)
{
	std::vector<int>	v;

	for (size_t i = 1; i < 6; i++)
		v.push_back(2 * i + 1);	

	std::vector<int>::iterator	vIter;
	std::vector<int>::iterator	vIter2;
	std::vector<int>::iterator	vIter3;

	std::cout << "ORIGINAL" << std::endl;	
	for (vIter = v.begin(); vIter != v.end(); vIter++)
		std::cout << *vIter << "\t";
	std::cout << std::endl;

	std::cout << "RANGE" << std::endl;
	vIter = v.begin();
	vIter2 = vIter + 1;
	vIter3 = vIter + 2;
	std::cout << *vIter << "\t" << *vIter2 << "\t" << *vIter3 << std::endl;

	std::vector<int>				test(vIter, vIter3);
	std::vector<int>::iterator		testiterator;

	std::cout << "ORIGINAL - testing range constructor" << std::endl;	
	for (testiterator = test.begin(); testiterator != test.end(); testiterator++)
		std::cout << *testiterator << "\t";
	std::cout << std::endl << std::endl;




	ft::vector<int>		mv;

	for (size_t i = 0; i < v.size(); i++)
		mv.push_back(v[i]);

	ft::vector<int>::iterator	mvIter;
	ft::vector<int>::iterator	mvIter2;
	ft::vector<int>::iterator	mvIter3;

	std::cout << "MINE" << std::endl;	
	for (mvIter = mv.begin(); mvIter != mv.end(); mvIter++)
		std::cout << *mvIter << "\t";
	std::cout << std::endl;

	std::cout << "RANGE" << std::endl;
	mvIter = mv.begin();
	mvIter2 = mvIter + 1;
	mvIter3 = mvIter + 2;
	std::cout << *mvIter << "\t" << *mvIter2 << "\t" << *mvIter3 << std::endl;

	ft::vector<int>				mtest(mvIter, mvIter3);
	ft::vector<int>::iterator	mtestiterator;

	std::cout << "MINE - testing range constructor" << std::endl;	
	for (mtestiterator = mtest.begin(); mtestiterator != mtest.end(); mtestiterator++)
		std::cout << *mtestiterator << "\t";
	std::cout << std::endl;	

	ft::vector<int>				fill(20, 42);
	ft::vector<int>::iterator	fillIter;

	std::cout << "MINE - testing fill constructor" << std::endl;	
	for (fillIter = fill.begin(); fillIter != fill.end(); fillIter++)
		std::cout << *fillIter<< "\t";
	std::cout << std::endl;

	ft::vector<int>				mcopy(fill);
	ft::vector<int>::iterator	copyIter;

	std::cout << "MINE - testing copy constructor" << std::endl;	
	for (copyIter = mcopy.begin(); copyIter != mcopy.end(); copyIter++)
		std::cout << *copyIter << "\t";
	std::cout << std::endl;
	return (0);
}
