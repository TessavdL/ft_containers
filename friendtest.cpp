/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   friendtest.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 17:58:06 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/10/13 13:50:36 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <functional>	// for std::less, should include own compare later
# include <iostream>	// for output, prob remove later
# include <utility>		// for std::pair, should include own pair later
# include <memory>		// for std::allocator

namespace ft {
template<typename, typename>
class testpair;
}

template<typename>
class testnode;

template<class T = ft::testpair<class T1, class T2>>
class testiterator
{
	public:
		typedef T				value_type;
		typedef	value_type*		pointer;
		typedef value_type&		reference;

		testiterator(const value_type& val, testnode<value_type>* n) : _ptr(val), _node(n)
		{
			//parameter constructor
		}
		testiterator	operator++(void)
		{
			this->_node = this->_node->next();
			return (*this);
		}
		reference	operator*(void)
		{
			return (this->_node->data);
		}

	private:
		value_type				_ptr;
		testnode<value_type>*	_node;
};

template<class Key, class T>
class testmap
{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::testpair<const key_type, mapped_type>	value_type;
		typedef testiterator<value_type>				iterator;
		testmap(const value_type& val)
		{
			std::allocator<testnode<value_type>>	alloc;
			testnode<value_type>*					new_node = alloc.allocate(1);

			alloc.construct(new_node, testnode<value_type>(val));
			this->_root = new_node;
			//parameter constructor
		}
		void	insert(const value_type& val)
		{
			std::allocator<testnode<value_type>>	alloc;
			testnode<value_type>*					new_node = alloc.allocate(1);

			alloc.construct(new_node, testnode<value_type>(val));
			this->_root->right = new_node;
		}
		iterator	begin(void)
		{
			return (iterator(this->_root->data, this->_root));
		}
	private:
		testnode<value_type>*	_root;
};

template<class T = ft::testpair<class T1, class T2>>
class testnode
{
	public:
		typedef T1			key_type;
		typedef T2			mapped_type;
		typedef T			value_type;
		typedef value_type*	pointer; // how :(

		testnode*	left;
		testnode*	right;
		testnode*	parent;
		value_type	data;

		testnode(const value_type& val) : left(nullptr), right(nullptr), parent(nullptr), data(val)
		{
			//parameter constructor
		}
		testnode*	next(void)
		{
			return (this->right);
		}
};

namespace ft{
template<class T1, class T2>
class testpair
{
	public:
		typedef T1	first_type;
		typedef	T2	second_type;
	
		first_type	first;
		second_type	second;

		testpair(const T1& one, const T2& two) : first(one), second(two)
		{
			//parameter constructor
		}
};
}

int	main(void)
{
	ft::testpair<const int, int>	p1(1, 2);
	ft::testpair<const int, int>	p2(4, 5);
	testmap<int, int>	m(p1);

	m.insert(p2);

	testmap<int, int>::iterator	it = m.begin();
	std::cout << (*it).first << std::endl;
	std::cout << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << std::endl;
	std::cout << (*it).second << std::endl;
}
