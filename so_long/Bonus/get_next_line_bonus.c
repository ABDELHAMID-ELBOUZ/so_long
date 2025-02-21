/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:10:48 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/07 15:12:13 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		str1;
	int		str2;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	join = malloc((str1 + str2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, str1 + 1);
	ft_strlcat(join, s2, (str1 + str2 + 1));
	return (join);
}

ssize_t	r_line(int fd, char **str)
{
	char	*buff;
	char	*tmp;
	ssize_t	r_size;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(*str), *str = NULL, -1);
	r_size = read(fd, buff, BUFFER_SIZE);
	if (r_size <= 0)
		return (free(buff), r_size);
	buff[r_size] = '\0';
	tmp = ft_strjoin(*str, buff);
	if (!tmp)
		return (free(buff), free(*str), *str = NULL, -1);
	free(*str);
	free(buff);
	*str = tmp;
	return (r_size);
}

char	*first_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc(sizeof(char) * i + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, i + 1);
	return (result);
}

char	*second_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str[i])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = ft_strdup(str + i);
	if (!result)
		return (free(str), NULL);
	free (str);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	ssize_t		r_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX \
		|| read(fd, NULL, 0) < 0)
		return (free (str), str = NULL, NULL);
	while (!ft_strchr(str, '\n'))
	{
		r_size = r_line(fd, &str);
		if (r_size < 0)
			return (free (str), str = NULL, NULL);
		if (r_size == 0)
			break ;
	}
	if (!str || str[0] == '\0')
		return (free (str), str = NULL, NULL);
	result = first_line(str);
	if (!result)
		return (free (str), str = NULL, NULL);
	str = second_line(str);
	return (result);
}
