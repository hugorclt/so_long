# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:25:41 by hrecolet          #+#    #+#              #
#    Updated: 2022/01/12 16:09:29 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INC			=	include

SRCS		=	srcs/ft_movements.c srcs/collectibles.c srcs/movements_utils.c \
				srcs/read_map.c srcs/parse_map.c srcs/main.c get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c srcs/size_window.c \
				printf/ft_printf.c printf/ft_printf_utils.c printf/ft_utils_len.c \
				printf/ft_utils_char.c printf/ft_utils_putnbr.c srcs/check_map.c \
				srcs/ft_free.c srcs/check_maps_utils.c

MLX			=	/usr/local/lib/

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

RM			=	rm -f

CFLAGS 		=	-Wall -Werror -Wextra 
FLAGS_MLX	=	-lmlx -framework OpenGl -framework Appkit

all			:	$(NAME)

%.o			:  %.c
				$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME)		:	$(OBJS)
				$(CC) $(OBJS) $(FLAGS_MLX) -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re 			:	fclean all
