/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:20:13 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/19 12:56:08 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handl_esc_key(int keycode, t_game *game)
{
	int			i;

	i = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 124 || keycode == 2)
		i = move_right(game);
	else if (keycode == 123 || keycode == 0)
		i = move_left(game);
	else if (keycode == 126 || keycode == 13)
		i = move_up(game);
	else if (keycode == 125 || keycode == 1)
		i = move_down(game);
	if (i == 1)
		ft_printf("%d\n", ++game->count);
	return (0);
}

int	handl_red_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
