/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:38:22 by aelbouz           #+#    #+#             */
/*   Updated: 2025/01/26 10:26:58 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ext(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len <= 4)
		return (ft_printf("Error\nuse ./so_long [map].ber\n"), exit (0), 0);
	if (ft_strncmp(file_path + len - 4, ".ber", len) != 0)
		return (ft_printf("Error\nuse ./so_long [map].ber\n"), exit (0), 0);
	return (1);
}

size_t	map_rect(char **map)
{
	int		i;
	size_t	first_line;
	size_t	line;

	if (!map || !map[0])
		return (0);
	first_line = ft_strlen(map[0]);
	if (map[0][first_line - 1] == '\n')
		first_line--;
	i = 1;
	if (!map[1])
		return (0);
	line = ft_strlen(map[i]);
	while (map[i])
	{
		line = ft_strlen(map[i]);
		if (map[i][line - 1] == '\n')
			line--;
		if (line != first_line)
			return (0);
		i++;
	}
	return (1);
}

int	lines_count(char *filename)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nfile not opening error\n"), exit (0), 0);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (count);
}

char	**read_map(char *filename, int count_lines)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * count_lines + 1);
	if (!map)
		return (ft_printf("Error\n Malloc error\n"), exit(0), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nfile not openinig error\n"), exit(0), NULL);
	i = 0;
	while (i < count_lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_map(map, i);
			close(fd);
			return (ft_printf("Error\nreading file error\n"), exit(0), NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
