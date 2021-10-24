/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IteratorTraits.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 15:26:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/20 14:30:39 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>

/*
iteratator_category	input_iterator_tag
					output_iterator_tag
					forward_iterator_tag
					bidirectional_iterator_tag
					random_access_iterator_tag
*/

namespace ft {
template <class Iterator>
class iterator_traits
{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category	iterator_category;
};
}

/*
iterator tags
*/

namespace ft {
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}

#endif