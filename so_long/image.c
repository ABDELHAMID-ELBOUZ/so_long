/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:58:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/01 16:06:21 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_to_image(t_game *game, char **map)
{
	int	i;
	int	j;

	game->w_img = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm", &i, &j);
	game->s_img = mlx_xpm_file_to_image(game->mlx, "./images/spac.xpm", &i, &j);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "./images/coin.xpm", &i, &j);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "./images/char.xpm", &i, &j);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &i, &j);
	if (!game->e_img || !game->w_img || !game->s_img \
		|| !game->c_img || !game->p_img)
		return (ft_printf("Error\neroor images\n"), exit(0), 0);
	img_to_window(game, map);
	return (1);
}

void	placing(t_game *game, int rows, int columns, void *which)
{
	mlx_put_image_to_window(game->mlx, game->win, which, \
		rows * 64, columns * 64);
}
