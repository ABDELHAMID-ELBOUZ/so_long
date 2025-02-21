/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:14:14 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/07 15:13:27 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_puthexa((unsigned long)ptr, 'x');
	return (i);
}
