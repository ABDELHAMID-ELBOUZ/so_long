/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:48:11 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/17 10:14:16 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_map_size(char *filename, int *rows, int *columns)
{
	int		fd;
	char	*line;

	*rows = lines_count(filename);
	*columns = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nfile not found\n");
		exit(1);
	}
	line = get_next_line(fd);
	if (line)
	{
		*columns = ft_strlen(line);
		if (line[*columns - 1] == '\n')
			(*columns)--;
		free(line);
	}
	if (*rows > 21 || *columns > 40)
	{
		ft_printf("Error\nthe map not valid\n");
		exit(1);
	}
	close(fd);
}

void	img_to_window(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (map[y][x] == '1')
				placing(game, y, x, game->w_img);
			else if (map[y][x] == 'E')
				placing(game, y, x, game->e_img);
			else if (map[y][x] == 'P')
				placing_player(game, y, x);
			else if (map[y][x] == 'C')
				placing_coins(game, y, x);
			else if (map[y][x] == '0')
				placing(game, y, x, game->s_img);
			x++;
		}
		y++;
	}
}

void	creat_window(t_game *game, int columns, int rows)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, columns * 64, rows * 64, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		exit(1);
	}
	mlx_hook(game->win, 2, 0, handl_esc_key, game);
	mlx_hook(game->win, 17, 0, handl_red_cross, game);
}
