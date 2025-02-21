/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:11:30 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/07 15:13:40 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
	}
	i += ft_putchar(nb % 10 + 48);
	return (i);
}
