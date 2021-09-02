/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   IteratorTraits.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 15:26:55 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/17 15:35:34 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

template <class Iterator>
class IteratorTraits
{
  typedef typename Iterator::difference_type	difference_type;
  typedef typename Iterator::value_type			value_type;
  typedef typename Iterator::pointer			pointer;
  typedef typename Iterator::reference 			reference;
  typedef typename Iterator::iterator_category	iterator_category;
};

#endif