			// void	reserve(size_type new_cap)
			// {
			// 	if (new_cap <= this->_capacity)
			// 	{
			// 		return ;
			// 	}
				
			// 	value_type*	temp = this->_alloc.allocate(new_cap);

			// 	if (this->_capacity > 0)
			// 	{
			// 		for (size_type i = 0; i < this->_size; i++)
			// 		{
			// 			this->_alloc.construct(temp + i, *(this->_first_element + i));
			// 			this->_alloc.destroy(this->_first_element + i);
			// 		}
			// 		this->_alloc.deallocate(this->_first_element, this->_capacity);
			// 	}
			// 	this->_first_element = temp;
			// 	this->_capacity = new_cap;
			// 	return ;
			// }



			// invalid range causes undefined behavior
			// iterator	erase(iterator first, iterator last)
			// {
			// 	difference_type	i_first	= first - this->begin();
			// 	difference_type	i_last = last - this->begin();
			// 	difference_type	n = last - first;

			// 	for (iterator it = last; it != this->end(); it++, i_first++, i_last++)
			// 	{
			// 		this->_alloc.destroy(&this->_first_element[i_first]);
			// 		this->_alloc.construct(&this->_first_element[i_first], this->_first_element[i_last]);
			// 	}
			// 	for (difference_type i = 0; i < n; i++, i_first++)
			// 	{
			// 		this->_alloc.destroy(&this->_first_element[i_first]);
			// 	}
			// 	this->_size -= n;
			// 	return (this->begin() + i_first);
			// }

						// void	push_back(const T& value)
			// {
			// 	if (this->_capacity == 0)
			// 	{
			// 		this->_first_element = this->_alloc.allocate(1);
			// 		this->_alloc.construct(this->_first_element, value);
			// 		this->_capacity = 1;
			// 		this->_size = 1;
			// 		return ;
			// 	}
			// 	if (this->_size == this->_capacity)
			// 	{
			// 		this->_reallocate(this->_capacity * 2);
			// 	}
			// 	this->_alloc.construct(this->_first_element + this->_size, value);
			// 	this->_size++;
			// 	return ;
			// }