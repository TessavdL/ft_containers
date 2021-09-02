/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_map.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 13:47:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/08/20 16:44:25 by tevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Map.hpp"
# include <iostream>
# include <map>

void	map_basic(void)
{
	std::map<std::string, int>	map_default;

	map_default["apple"] = 10;
	map_default["banana"] = 20;
	map_default["kiwi"] = 30;
	map_default["orange"] = 40;
	map_default["peach"] = 50;
	map_default["mango"] = 60;
	for (std::map<std::string, int>::iterator it = map_default.begin(); it != map_default.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << "size of map_default after adding 6 elements " << map_default.size() << std::endl;

	std::map<std::string, int> map_range(map_default.begin(), map_default.end());
	for (std::map<std::string, int>::iterator it = map_range.begin(); it != map_range.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << "size of map_range after calling range constructor " << map_range.size() << std::endl;

	std::map<std::string, int> map_copy(map_default);
	for (std::map<std::string, int>::iterator it = map_copy.begin(); it != map_copy.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << "size of map_copy calling copy constructor " << map_copy.size() << std::endl;
	
	return ;
}

void	my_map_basic(void)
{
	Map<std::string, int>		my_map_default;
	std::map<std::string, int>	map_default;

	map_default["apple"] = 10;
	map_default["banana"] = 20;
	map_default["kiwi"] = 30;
	map_default["orange"] = 40;
	map_default["peach"] = 50;
	map_default["mango"] = 60;
	for (std::map<std::string, int>::iterator it = map_default.begin(); it != map_default.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << "size of my_map_default = " << my_map_default.size() << std::endl;

	Map<std::string, int> my_map_range(map_default.begin(), map_default.end());
	// Map<std::string, int>::iterator it = my_map_range.begin();
	// std::cout << it->first << " " << it->second << std::endl;
	// for (std::map<std::string, int>::iterator it = my_map_range.begin(); it != map_range.end(); it++)
	// {
		// std::cout << it->first << " " << it->second << std::endl;
	// }
	std::cout << "size of my_map_range after calling range constructor " << my_map_range.size() << std::endl;
	std::cout << std::boolalpha << ("apple" < "banana") << std::endl;
	return ;
}

int	main(void)
{
	// map_basic();
	my_map_basic();
	return (0);
}
