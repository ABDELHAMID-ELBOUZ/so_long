/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:48:11 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/03 09:57:45 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(char *filename, int *rows, int *columns)
{
	int		fd;
	char	*line;

	*rows = lines_count(filename);
	*columns = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nfile not opening error\n");
		exit(0);
	}
	line = get_next_line(fd);
	if (line)
	{
		*columns = ft_strlen(line);
		if (line[*columns - 1] == '\n')
			(*columns)--;
		free(line);
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
				placing(game, y, x, game->p_img);
			else if (map[y][x] == 'C')
				placing(game, y, x, game->c_img);
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
	game->win = mlx_new_window(game->mlx, columns * 64, rows * 64, "so_long");
	if (!game->win)
	{
		free(game->win);
		exit(0);
	}
	mlx_key_hook(game->win, handl_esc_key, game);
	mlx_hook(game->win, 17, 0, handl_red_cross, game);
}
