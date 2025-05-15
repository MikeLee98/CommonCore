# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 20:37:51 by mario             #+#    #+#              #
#    Updated: 2025/05/14 22:05:45 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_printf.c ft_printf_utils.c
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
