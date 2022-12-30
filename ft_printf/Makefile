# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwai-kea <nwai-kea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:45:52 by nwai-kea          #+#    #+#              #
#    Updated: 2022/11/29 14:16:17 by nwai-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = ft_printf.h

CC = gcc
CFLAG = -Wall -Wextra -Werror -I $(INCLUDES)

AR = ar crs

RM = rm -rf

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_pointer.c \
		ft_hex.c \
		ft_putchar_fd.c \
		ft_itoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -c $(CFLAG) $(SRCS) 
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

