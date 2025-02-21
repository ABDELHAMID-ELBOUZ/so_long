/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:58:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/11 09:40:28 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_to_image(t_game *game)
{
	int	i;
	int	j;

	game->w_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/wall.xpm", &i, &j);
	game->s_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/road.xpm", &i, &j);
	game->c_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/coin.xpm", &i, &j);
	game->p_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/char.xpm", &i, &j);
	game->e_img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/exit.xpm", &i, &j);
	if (!game->e_img || !game->w_img || !game->s_img \
		|| !game->c_img || !game->p_img)
		return (0);
	return (1);
}

void	placing(t_game *game, int x, int y, void *which)
{
	mlx_put_image_to_window(game->mlx, game->win, which, \
		y * 64, x * 64);
}

void	placing_player(t_game *game, int x, int y)
{
	game->x = x;
	game->y = y;
	mlx_put_image_to_window(game->mlx, game->win, game->p_img \
		, y * 64, x * 64);
}

void	placing_coins(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->c_img, \
		y * 64, x * 64);
	game->coins++;
}
