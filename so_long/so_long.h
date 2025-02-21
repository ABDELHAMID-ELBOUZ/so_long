/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:30:52 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/11 09:33:36 by aelbouz          ###   ########.fr       */
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

typedef struct s_game
{
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*s_img;
	void	*e_img;
	void	*en_img;
	void	*mlx;
	void	*win;
	int		rows;
	int		columns;
	char	**map;
	int		coins;
	int		x;
	int		y;
	int		count;
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		handl_esc_key(int keycode, t_game *game);
int		handl_red_cross(t_game *game);
int		check_ext(char *file_path);
size_t	map_rect(char **map);
void	free_map(char **map, int j);
char	**read_map(char *filename, int i);
int		lines_count(char *filename);
int		check_map_walls(char **map);
int		cheek_elem(char **map, int map_exit, int collectable, int start);
int		map_valid(char **map);
void	creat_window(t_game *game, int rows, int cols);
void	img_to_window(t_game *game, char **map);
void	get_map_size(char *filename, int *rows, int *cols);
int		file_to_image(t_game *game);
void	placing(t_game *game, int rows, int columns, void *which);
void	placing_player(t_game *game, int x, int y);
void	placing_coins(t_game *game, int y, int x);
int		move_right(t_game *game);
int		move_left(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
void	flood_fill(char **map, size_t x, size_t y, size_t count_lines);
int		test_fl_fi(char **map);
int		check_fl_fi(t_game *game);

#endif