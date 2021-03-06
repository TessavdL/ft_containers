/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testreverseiteratorvector.cpp                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 22:08:50 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/23 13:44:34 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ReverseIterator.hpp"
#include "./includes/Vector.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	// --------------------------VECTOR OF INTS------------------------
	std::vector<int>							v;
	std::vector<int>::iterator					Iter;
	std::vector<int>::reverse_iterator			revIter;
	std::vector<int>::const_iterator			constIter;
	std::vector<int>::const_reverse_iterator	constrevIter;

	for (size_t i = 1; i < 6; i++)
		v.push_back(2 * i + 1);

	// --------------------------PRINT WITH DEREFERENCED NORMAL ITERATOR------------------------
	std::cout << "ORIGINAL - * normal iterator" << std::endl;
	for (Iter = v.begin(); Iter != v.end(); Iter++)
		std::cout << *Iter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED REVERSE ITERATOR------------------------
	std::cout << "ORIGINAL - * reverse iterator" << std::endl;
	for (revIter = v.rbegin(); revIter != v.rend(); revIter++)
		std::cout << *revIter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED CONST ITERATOR------------------------
	std::cout << "ORIGINAL - * const iterator" << std::endl;	
	for (constIter = v.begin(); constIter != v.end(); constIter++)
		std::cout << *constIter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED CONST REVERSE ITERATOR------------------------
	std::cout << "ORIGINAL - * const reverse iterator" << std::endl;
	for (constrevIter = v.rbegin(); constrevIter != v.rend(); constrevIter++)
		std::cout << *constrevIter << "\t";
	std::cout << std::endl;

	// the constiterator does not allow the value to be changed -> compilation error
	// *constIter = 4;

	// --------------------------MY VECTOR OF INTS------------------------
	ft::vector<int>							mv;
	ft::vector<int>::iterator				mIter;
	ft::vector<int>::reverse_iterator		revmIter;
	ft::vector<int>::const_iterator			constmIter;
	ft::vector<int>::const_reverse_iterator	constrevmIter;

	for (size_t i = 0; i < v.size(); i++)
		mv.push_back(v[i]);

	// --------------------------PRINT WITH MY OWN DEREFERENCED NORMAL ITERATOR------------------------
	std::cout << "MINE - * normal iterator" << std::endl;	
	for (mIter = mv.begin(); mIter != mv.end(); mIter++)
		std::cout << *mIter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH MY OWN DEREFERENCED REVERSE ITERATOR------------------------
	std::cout << "MINE - * reverse iterator" << std::endl;	
	for (ft::vector<int>::reverse_iterator mrevIter = mv.rbegin(); mrevIter != mv.rend(); ++mrevIter)
			std::cout << *mrevIter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED CONST ITERATOR------------------------
	std::cout << "MINE - * const iterator" << std::endl;
	for (constmIter = mv.begin(); constmIter != mv.end(); constmIter++)
		std::cout << *constmIter << "\t";
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED CONST REVERSE ITERATOR------------------------
	std::cout << "MINE - * const reverse iterator" << std::endl;
	for (constrevmIter = mv.rbegin(); constrevmIter != mv.rend(); constrevmIter++)
		std::cout << *constrevmIter << "\t";
	std::cout << std::endl;


	// the constiterator does not allow the value to be changed -> compilation error
	// *constmIter = 4;

	// --------------------------VECTOR OF PAIRS------------------------
	std::vector<std::pair<int, int> >					vp;
	std::vector<std::pair<int, int> >::iterator			vpIter;
	std::vector<std::pair<int, int> >::reverse_iterator	revpIter;
	std::pair<int, int> pair(0, 1);
	std::pair<int, int> pair2(2, 3);
	std::pair<int, int> pair3(4, 5);

	std::cout << std::endl;
	std::cout << "PAIRS" << std::endl;
	std::cout << pair.first << " " << pair.second << std::endl;
	std::cout << pair2.first << " " << pair2.second << std::endl;
	std::cout << pair3.first << " " << pair3.second << std::endl;
	std::cout << std::endl;
	vp.push_back(pair);
	vp.push_back(pair2);
	vp.push_back(pair3);

	// --------------------------PRINT WITH DEREFERENCED NORMAL ITERATOR------------------------
	std::cout << "ORIGINAL - * normal iterator" << std::endl;	
	for (vpIter = vp.begin(); vpIter != vp.end(); vpIter++)
		std::cout << (*vpIter).first << " " << (*vpIter).second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH -> NORMAL ITERATOR------------------------
	std::cout << "ORIGINAL - -> normal iterator" << std::endl;
	for (vpIter = vp.begin(); vpIter != vp.end(); vpIter++)
		std::cout << vpIter->first << " " << vpIter->second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH [] NORMAL ITERATOR------------------------
	std::cout << "ORIGINAL - [] normal iterator" << std::endl;
	vpIter = vp.begin();
	std::cout << vpIter[0].first << " " << vpIter[0].second << std::endl;
	std::cout << vpIter[1].first << " " << vpIter[1].second << std::endl;
	std::cout << vpIter[2].first << " " << vpIter[2].second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED REVERSE ITERATOR------------------------
	std::cout << "ORIGINAL - * reverse iterator" << std::endl;	
	for (revpIter = vp.rbegin(); revpIter != vp.rend(); revpIter++)
		std::cout << (*revpIter).first << " " << (*revpIter).second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH -> REVERSE ITERATOR------------------------
	std::cout << "ORIGINAL - -> reverse iterator" << std::endl;
	for (revpIter = vp.rbegin(); revpIter != vp.rend(); revpIter++)
		std::cout << revpIter->first << " " << revpIter->second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH [] REVERSE ITERATOR------------------------
	std::cout << "ORIGINAL - [] reverse iterator" << std::endl;
	revpIter = vp.rbegin();
	std::cout << revpIter[0].first << " " << revpIter[0].second << std::endl;
	std::cout << revpIter[1].first << " " << revpIter[1].second << std::endl;
	std::cout << revpIter[2].first << " " << revpIter[2].second << std::endl;
	std::cout << std::endl;

	// --------------------------MY VECTOR OF PAIRS------------------------
	ft::vector<std::pair<int, int> >						mvp;
	ft::vector<std::pair<int, int> >::iterator			mvpIter;
	ft::vector<std::pair<int, int> >::reverse_iterator	mrevpIter;
	mvp.push_back(pair);
	mvp.push_back(pair2);
	mvp.push_back(pair3);

	// --------------------------PRINT WITH DEREFERENCED NORMAL ITERATOR------------------------
	std::cout << "MINE - * normal iterator" << std::endl;	
	for (mvpIter = mvp.begin(); mvpIter != mvp.end(); mvpIter++)
		std::cout << (*mvpIter).first << " " << (*mvpIter).second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH -> NORMAL ITERATOR------------------------
	std::cout << "MINE - -> normal iterator" << std::endl;
	for (mvpIter = mvp.begin(); mvpIter != mvp.end(); mvpIter++)
		std::cout << mvpIter->first << " " << mvpIter->second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH [] NORMAL ITERATOR------------------------
	std::cout << "MINE - [] normal iterator" << std::endl;
	mvpIter = mvp.begin();
	std::cout << mvpIter[0].first << " " << mvpIter[0].second << std::endl;
	std::cout << mvpIter[1].first << " " << mvpIter[1].second << std::endl;
	std::cout << mvpIter[2].first << " " << mvpIter[2].second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH DEREFERENCED REVERSE ITERATOR------------------------
	std::cout << "MINE - * reverse iterator" << std::endl;	
	for (mrevpIter = mvp.rbegin(); mrevpIter != mvp.rend(); ++mrevpIter)
	std::cout << (*mrevpIter).first << " " << (*mrevpIter).second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH -> REVERSE ITERATOR------------------------
	std::cout << "MINE - -> reverse iterator" << std::endl;
	for (mrevpIter = mvp.rbegin(); mrevpIter != mvp.rend(); ++mrevpIter)
	std::cout << mrevpIter->first << " " << mrevpIter->second << std::endl;
	std::cout << std::endl;

	// --------------------------PRINT WITH [] REVERSE ITERATOR------------------------
	std::cout << "MINE - [] reverse iterator" << std::endl;
	mrevpIter = mvp.rbegin();
	std::cout << mrevpIter[0].first << " " << mrevpIter[0].second << std::endl;
	std::cout << mrevpIter[1].first << " " << mrevpIter[1].second << std::endl;
	std::cout << mrevpIter[2].first << " " << mrevpIter[2].second << std::endl;
	std::cout << std::endl;

	return (0);
}
