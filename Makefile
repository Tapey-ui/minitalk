# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 16:10:56 by nwai-kea          #+#    #+#              #
#    Updated: 2022/12/28 17:43:27 by nwai-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

LIBFT = libft/libft.a
LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFTPRINTF) server client

bonus: all

server: server.o
		$(CC) $(CFLAGS) $(LIBFTPRINTF) $(LIBFT) -o $@ server.o

client: client.o
		$(CC) $(CFLAGS) $(LIBFTPRINTF) $(LIBFT) -o $@ client.o

%.o: %.c
		$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
		$(RM) server client $(LIBFT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all bonus clean fclean re
