/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:20:06 by aelbouz           #+#    #+#             */
/*   Updated: 2025/01/24 17:43:34 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_walls(char **map)
{
	int	i;
	int	width;
	int	length;

	width = 0;
	while (map[width])
		width++;
	width--;
	length = ft_strlen(map[0]);
	length--;
	i = 0;
	while (i < length)
	{
		if (map[0][i] != '1' || map[width][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	cheek_elem(char **map, int map_exit, int collectable, int start)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j - 1] != '0' && map[i][j - 1] != '1'
			&& map[i][j - 1] != 'E' && map[i][j - 1] != 'C'
			&& map[i][j - 1] != 'P')
				return (ft_printf("Error\nElement not valide\n"), exit(0), 0);
			else if (map[i][j] == 'C')
				collectable++;
			else if (map[i][j] == 'E')
				map_exit++;
			else if (map[i][j] == 'P')
				start++;
			j++;
		}
	}
	if (collectable < 1 || start != 1 || map_exit != 1)
		return (0);
	return (1);
}

int	map_valid(char **map)
{
	int	count_lines;

	if (!check_ext(map[1]))
		return (ft_printf("Error\nuse : ./so_long [map].ber\n"),
			free_map(map, 0), exit(0), 1);
	count_lines = lines_count(map[1]);
	map = read_map(map[1], count_lines);
	if (!map_rect(map))
		return (ft_printf("Error\nmap not rectangle\n"),
			free_map(map, 0), exit(0), 0);
	else if (!check_map_walls(map))
		return (ft_printf("Error\nthe map not closed by walls\n"),
			free_map(map, 0), exit(0), 0);
	else if (!cheek_elem(map, 0, 0, 0))
		return (ft_printf("Error\nthe map not valid\n"),
			free_map(map, 0), exit(0), 0);
	free_map(map, 0);
	return (1);
}
