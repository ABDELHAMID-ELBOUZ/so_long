/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:01 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/07 15:14:27 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i += ft_format(*format, args);
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
