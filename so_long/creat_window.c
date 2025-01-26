/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:48:11 by aelbouz           #+#    #+#             */
/*   Updated: 2025/01/26 15:09:29 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;

	*rows = lines_count(filename);
	*cols = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nfile not opening error\n");
		exit(0);
	}
	line = get_next_line(fd);
	if (line)
	{
		*cols = ft_strlen(line);
		if (line[*cols - 1] == '\n')
			(*cols)--;
		free(line);
	}
	close (fd);
}

void	img_to_window(t_game *game, char **map, int rows, int cols)
{
	int	x;
	int	y;

	y = 0;
	ft_printf("rows:%d\ncols:%d\n", rows, cols);
	if (!map) // Check if map is NULL
	{
		ft_printf("Error: map is NULL\n");
		return;
	}
	while (y < rows)
	{
		if (!map[y]) // Check if map[y] is NULL
		{
			ft_printf("Error: map[%d][%d] is NULL\n", y, x);
			break;
		}
		x = 0;
		while (x < cols)
		{
			ft_printf("x:%d\ny:%d\n", x, y);
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->w_img, x * 128, y * 128);
			}
			if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->e_img, x * 128, y * 128);
			if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->p_img, x * 128, y * 128);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c_img, x * 128, y * 128);
			x++;
		}
		y++;
	}
}

void	creat_window(t_data *data, int rows, int cols)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, rows * 128, cols * 128, "so_long");
	if (!data->win)
	{
		free(data->win);
		exit(0);
	}
	mlx_key_hook(data->win, handl_esc_key, data);
	mlx_hook(data->win, 17, 0, handl_red_cross, data);
}
