# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 17:30:12 by aelbouz           #+#    #+#              #
#    Updated: 2025/02/02 09:45:27 by aelbouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -g -Wall -Wextra -Werror -Imlx
AR = ar rcs
RM = rm -f
SRCS = image.c cheek_map.c main.c map.c handl_keys.c creat_window.c ft_strncmp.c \
ft_format.c ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putptr.c ft_putstr.c \
ft_putunint.c get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c so_long.h
	$(CC) -c $(FLAGS)  $< -o $@
clean :
	$(RM) $(OBJS)
fclean :clean
	$(RM) $(NAME)
re : fclean all
