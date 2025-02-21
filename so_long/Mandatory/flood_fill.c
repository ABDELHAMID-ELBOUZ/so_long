/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:43:21 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/21 15:49:09 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, size_t x, size_t y, size_t count_lines)
{
	if (x < 0 || y < 0 || x >= count_lines || y >= ft_strlen(map[0]))
		return ;
	if (map[x][y] == 'E')
		map[x][y] = '1';
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill (map, x + 1, y, count_lines);
	flood_fill (map, x - 1, y, count_lines);
	flood_fill (map, x, y + 1, count_lines);
	flood_fill (map, x, y - 1, count_lines);
}

int	test_fl_fi(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_fl_fi( t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				flood_fill(game->map, i, j, game->rows);
				if (test_fl_fi(game->map) == 0)
					return (ft_printf("Error\nthe map not valid\n"), \
						free(game->map), exit(1), 0);
			}
			j++;
		}
		i++;
	}
	return (free_map(game->map, 0), 1);
}
