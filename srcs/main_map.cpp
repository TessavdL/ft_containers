/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_map.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tevan-de <tevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 13:47:30 by tevan-de      #+#    #+#                 */
/*   Updated: 2021/11/03 17:36:55 by tevan-de      ########   odam.nl         */
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
	std::map<std::string, int>	map_default;

	map_default["apple"] = 10;
	map_default["banana"] = 20;
	map_default["kiwi"] = 30;
	map_default["orange"] = 40;
	map_default["peach"] = 50;
	map_default["mango"] = 60;
	std::cout << "size of map_default = " << map_default.size() << std::endl;
	for (std::map<std::string, int>::iterator it = map_default.begin(); it != map_default.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	std::cout << std::endl;

	std::map<std::string, int>	map_range(map_default.begin(), map_default.end());

	std::cout << "size of map_range = " << map_range.size() << std::endl;
	for (std::map<std::string, int>::iterator it = map_range.begin(); it != map_range.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	std::cout << std::endl;

	ft::map<std::string, int>	my_map_default;
	my_map_default["apple"] = 10;
	my_map_default["banana"] = 20;
	my_map_default["kiwi"] = 30;
	my_map_default["orange"] = 40;
	my_map_default["peach"] = 50;
	my_map_default["mango"] = 60;
	std::cout << "size of my_map_default = " << my_map_default.size() << std::endl;
	for (ft::map<std::string, int>::iterator it = my_map_default.begin(); it != my_map_default.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	std::cout << std::endl;

	ft::map<std::string, int>	my_map_range(my_map_default.begin(), my_map_default.end());

	std::cout << "size of my_map_range after calling range constructor " << my_map_range.size() << std::endl;
	for (ft::map<std::string, int>::iterator it = my_map_range.begin(); it != my_map_range.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}

	ft::map<std::string, int>	my_map_copy(my_map_default);

	std::cout << "size of my_map_copy after calling copy constructor " << my_map_range.size() << std::endl;
	for (ft::map<std::string, int>::iterator it = my_map_copy.begin(); it != my_map_copy.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	return ;

}

int	main(void)
{
	// map_basic();
	my_map_basic();
	return (0);
}
