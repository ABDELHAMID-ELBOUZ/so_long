/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:30:52 by aelbouz           #+#    #+#             */
/*   Updated: 2025/01/26 15:02:02 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		*img;
	int		length;
	int		width;
}	t_data;

typedef struct s_game
{
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*mlx;
	void	*win;
}	t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putunint(unsigned int nb);
int		ft_puthexa(unsigned long nb, char format);
int		ft_putptr(void *ptr);
int		ft_format(char format, va_list args);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
ssize_t	r_line(int fd, char **str);
char	*first_line(char *str);
char	*second_line(char *str);
char	*get_next_line(int fd);
int		handl_esc_key(int keycode, t_data *data);
int		handl_red_cross(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_ext(char *file_path);
size_t	map_rect(char **map);
void	free_map(char **map, int j);
int		open_map(char **av);
char	**read_map(char *filename, int count_lines);
int		lines_count(char *filename);
int		check_map_walls(char **map);
int		cheek_elem(char **map, int map_exit, int collectable, int start);
int		map_valid(char **map);
void	creat_window(t_data *data,  int rows, int cols);
void	img_to_window(t_game *game, char **map, int rows, int cols);
void	get_map_size(char *filename, int *rows, int *cols);

#endif