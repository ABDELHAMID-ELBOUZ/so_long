/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:58:58 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/07 17:14:59 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_right(t_game	*game)
{
	if (game->map[game->x][game->y + 1] == '1' || \
		(game->map[game->x][game->y + 1] == 'E' && game->coins != 0))
		return (0);
	game->map[game->x][game->y] = '0';
	placing(game, game->x, game->y, game->s_img);
	game->y = game->y + 1;
	if (game->map[game->x][game->y] == 'N')
		return (ft_printf("GAME OVER\n"), exit(0), 0);
	if (game->map[game->x][game->y] == 'C')
	{
		game->map[game->x][game->y] = '0';
		placing(game, game->x, game->y, game->s_img);
		game->coins--;
	}
	if (game->map[game->x][game->y] == 'E' && game->coins == 0)
	{
		ft_printf("YOU WIN\n");
		exit (0);
	}
	game->map[game->x][game->y] = 'P';
	placing_player(game, game->x, game->y);
	return (1);
}

int	move_left(t_game	*game)
{
	if (game->map[game->x][game->y - 1] == '1' || \
		(game->map[game->x][game->y - 1] == 'E' && game->coins != 0))
		return (0);
	game->map[game->x][game->y] = '0';
	placing(game, game->x, game->y, game->s_img);
	game->y = game->y - 1;
	if (game->map[game->x][game->y] == 'N')
		return (ft_printf("GAME OVER\n"), exit(0), 0);
	if (game->map[game->x][game->y] == 'C')
	{
		game->map[game->x][game->y] = '0';
		placing(game, game->x, game->y, game->s_img);
		game->coins--;
	}
	if (game->map[game->x][game->y] == 'E' && game->coins == 0)
	{
		ft_printf("YOU WIN\n");
		exit (0);
	}
	game->map[game->x][game->y] = 'P';
	placing_player(game, game->x, game->y);
	return (1);
}

int	move_down(t_game	*game)
{
	if (game->map[game->x + 1][game->y] == '1' || \
		(game->map[game->x + 1][game->y] == 'E' && game->coins != 0))
		return (0);
	game->map[game->x][game->y] = '0';
	placing(game, game->x, game->y, game->s_img);
	game->x = game->x + 1;
	if (game->map[game->x][game->y] == 'N')
		return (ft_printf("GAME OVER\n"), exit(0), 0);
	if (game->map[game->x][game->y] == 'C')
	{
		game->map[game->x][game->y] = '0';
		placing(game, game->x, game->y, game->s_img);
		game->coins--;
	}
	if (game->map[game->x][game->y] == 'E' && game->coins == 0)
	{
		ft_printf("YOU WIN\n");
		exit (0);
	}
	game->map[game->x][game->y] = 'P';
	placing_player(game, game->x, game->y);
	return (1);
}

int	move_up(t_game	*game)
{
	if (game->map[game->x - 1][game->y] == '1' || \
		(game->map[game->x - 1][game->y] == 'E' && game->coins != 0))
		return (0);
	game->map[game->x][game->y] = '0';
	placing(game, game->x, game->y, game->s_img);
	game->x = game->x - 1;
	if (game->map[game->x][game->y] == 'N')
		return (ft_printf("GAME OVER\n"), exit(0), 0);
	if (game->map[game->x][game->y] == 'C')
	{
		game->map[game->x][game->y] = '0';
		placing(game, game->x, game->y, game->s_img);
		game->coins--;
	}
	if (game->map[game->x][game->y] == 'E' && game->coins == 0)
	{
		ft_printf("YOU WIN\n");
		exit (0);
	}
	game->map[game->x][game->y] = 'P';
	placing_player(game, game->x, game->y);
	return (1);
}
