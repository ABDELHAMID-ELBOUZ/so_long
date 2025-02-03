/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:51:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/03 09:57:13 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int j)
{
	while (map[j])
	{
		free(map[j++]);
	}
	free (map);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Error\nuse ./so_long [map].ber\n"), exit (0), 0);
	if (!map_valid(av))
		return (free_map(av, 0), exit(0), 0);
	get_map_size(av[1], &game.rows, &game.columns);
	lines_count(av[1]);
	game.map = read_map(av[1], game.rows);
	if (!game.map)
		return (exit(0), 0);
	creat_window(&game, game.columns, game.rows);
	if (!file_to_image(&game))
		return (free_map(av, 0), exit(0), 0);
	img_to_window(&game, game.map);
	mlx_loop(game.mlx);
	return (0);
}
