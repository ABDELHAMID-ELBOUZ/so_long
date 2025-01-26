/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:51:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/01/26 15:36:03 by aelbouz          ###   ########.fr       */
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

void	f(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	int		rows;
	int		cols;
	t_data	data;
	// t_game	game;
	atexit(f);
	if (ac != 2)
		return (ft_printf("Error\nuse ./so_long [map].ber\n"), exit (0), 0);
	if (!map_valid(av))
		return (free_map(av, 0), exit(0), 0);
	get_map_size(av[1], &rows, &cols);
	creat_window(&data, cols, rows);
	// img_to_window(&game, av, rows, cols);
	mlx_loop(data.mlx);
	return (0);
}
