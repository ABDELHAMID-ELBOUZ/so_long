# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 17:30:12 by aelbouz           #+#    #+#              #
#    Updated: 2025/02/21 09:32:03 by aelbouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -g -Wall -Wextra -Werror -Imlx
RM = rm -f

SRCS = Mandatory/image.c Mandatory/cheek_map.c Mandatory/main.c Mandatory/map.c \
Mandatory/handl_keys.c Mandatory/creat_window.c Mandatory/ft_strncmp.c Mandatory/ft_format.c \
Mandatory/ft_printf.c Mandatory/ft_putchar.c Mandatory/ft_puthexa.c Mandatory/ft_putnbr.c \
Mandatory/ft_putptr.c Mandatory/ft_putstr.c Mandatory/ft_putunint.c Mandatory/get_next_line_utils.c \
Mandatory/get_next_line.c Mandatory/game.c Mandatory/flood_fill.c

BONUS_SRCS = Bonus/image_bonus.c Bonus/cheek_map_bonus.c Bonus/main_bonus.c Bonus/map_bonus.c \
Bonus/handl_keys_bonus.c Bonus/creat_window_bonus.c Bonus/ft_strncmp_bonus.c Bonus/ft_format_bonus.c \
Bonus/ft_printf_bonus.c Bonus/ft_putchar_bonus.c Bonus/ft_puthexa_bonus.c Bonus/ft_putnbr_bonus.c \
Bonus/ft_putptr_bonus.c Bonus/ft_putstr_bonus.c Bonus/ft_putunint_bonus.c Bonus/get_next_line_utils_bonus.c \
Bonus/get_next_line_bonus.c Bonus/game_bonus.c Bonus/flood_fill_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
all : $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(NAME_BONUS) :$(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -lmlx -framework OpenGL -framework AppKit -o  $(NAME_BONUS)
bonus : $(NAME_BONUS)
%.o: %.c so_long.h
	$(CC) -c $(FLAGS)  $< -o $@
clean :
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean :clean
	$(RM) $(NAME) $(NAME_BONUS)
re : fclean all