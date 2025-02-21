/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:51:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/17 10:26:40 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		return (0);
	get_map_size(av[1], &game.rows, &game.columns);
	game.map = read_map(av[1], 0);
	if (!game.map)
		return (exit(1), 0);
	check_fl_fi(&game);
	game.map = read_map(av[1], 0);
	if (!game.map)
		return (exit(1), 0);
	creat_window(&game, game.columns, game.rows);
	if (!file_to_image(&game))
		return (ft_printf("Error\nimage not valide"),
			free_map(game.map, 0), free(game.mlx), free(game.win), exit(1), 0);
	img_to_window(&game, game.map);
	mlx_loop(game.mlx);
	return (0);
}
