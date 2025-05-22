# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 20:37:51 by mario             #+#    #+#              #
#    Updated: 2025/05/15 14:04:55 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_printf.c ft_printf_putchar.c ft_printf_putstr.c ft_printf_putnbr.c \
ft_printf_putunsigned.c ft_printf_puthex.c ft_printf_putptr.c
OBJS=$(SRCS:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror -c -o

NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
