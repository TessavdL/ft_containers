/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   InputIterator.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:52:57 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/20 11:52:11 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

#include "./RandomAccessIterator.hpp"

template <class T>
class InputIterator : public RandomAccessIterator<T>
{
	public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~
		typedef T				value_type;
		typedef value_type*		pointer;
		typedef value_type&		reference;
		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~PUBLIC MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~
		// ----------------------------CONSTRUCTORS-----------------------------
		// default
		InputIterator(void) : RandomAccessIterator<T>()
		{
			std::cout << "Default Constructor of II called" << std::endl;
			return ;
		}
		// parameter
		InputIterator(pointer ptr) : RandomAccessIterator<T>(ptr)
		{
			std::cout << "Parameter Constructor of II called" << std::endl;
			return ;
		}
		// copy
		InputIterator(const InputIterator& other) : RandomAccessIterator<T>(other)
		{
			std::cout << "Copy Constructor of II called" << std::endl;
			return ;
		}

		// -----------------------------DESTRUCTOR------------------------------
		~InputIterator(void)
		{
			std::cout << "Destructor of II called" << std::endl;
			return ;
		}

		// ------------------------ASSIGNMENT OPERATOR--------------------------
		InputIterator&	operator=(const InputIterator& other)
		{
			RandomAccessIterator<T>::operator=(other);
			std::cout << "Assignment Operator of II called" << std::endl;
			return (*this);

		}

		// --------------------------INCREMENT OPERATORS------------------------
		// prefix increment
		InputIterator&	operator++(void)
		{
			RandomAccessIterator<T>::operator++();
			return (*this);
		}
		// postfix increment
		InputIterator	operator++(int n)
		{
			RandomAccessIterator<T>::operator++(n);
			return (*this);
		}

		// ------------------------MEMBER ACCESS OPERATORS----------------------
		// arrow operator
		pointer	operator->(void)
		{
			return (RandomAccessIterator<T>::operator->());
		}
		// dereference operator
		reference	operator*(void)
		{
			return (RandomAccessIterator<T>::operator*());
		}

		// -------------------------RELATIONAL OPERATORS------------------------
		// == operator, is equal to
		bool	operator==(const InputIterator& other) const
		{
			return (RandomAccessIterator<T>::operator==(other));
		}
		// != operator, is not equal to
		bool	operator!=(const InputIterator& other) const
		{
			return (RandomAccessIterator<T>::operator!=(other));
		}

	private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PRIVATE MEMBER TYPE~~~~~~~~~~~~~~~~~~~~~~~~~~~
		value_type*	_ptr;
};

#endif

