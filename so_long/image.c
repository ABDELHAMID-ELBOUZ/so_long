/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:58:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/02 18:30:40 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_to_image(t_game *game)
{
	int	i;
	int	j;

	game->w_img = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm", &i, &j);
	game->s_img = mlx_xpm_file_to_image(game->mlx, "./images/road.xpm", &i, &j);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "./images/coin.xpm", &i, &j);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "./images/char.xpm", &i, &j);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &i, &j);
	if (!game->e_img || !game->w_img || !game->s_img \
		|| !game->c_img || !game->p_img)
		return (ft_printf("Error\neroor images\n"), exit(0), 0);
	return (1);
}

void	placing(t_game *game, int y, int x, void *which)
{
	mlx_put_image_to_window(game->mlx, game->win, which, \
		x * 64, y * 64);
}
