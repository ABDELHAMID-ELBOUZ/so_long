/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheek_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:38:22 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/21 15:48:16 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len <= 4)
		return (0);
	if (ft_strncmp(file_path + len - 4, ".ber", 4) != 0)
		return (0);
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
	while (map[++i])
	{
		line = ft_strlen(map[i]);
		if (map[i][line - 1] == '\n')
			line--;
		if (line != first_line)
			return (0);
	}
	i--;
	if (map[i][ft_strlen(map[i]) - 1] == '\n')
		return (ft_printf("Error\nnew line exists"), exit (1), 0);
	return (1);
}

int	lines_count(char *filename)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nfile not found"), exit(1), 0);
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

char	**read_map(char *filename, int i)
{
	char	**map;
	int		fd;
	char	*line;

	map = malloc(sizeof(char *) * (lines_count(filename) + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nfile not found"), exit(1), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = malloc(sizeof(char *) * (ft_strlen(line) + 1));
		if (!map[i])
			return (free(line), free_map(map, i), close(fd), NULL);
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (close(fd), free(line), map);
}
