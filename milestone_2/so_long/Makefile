# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 17:21:52 by marioro2          #+#    #+#              #
#    Updated: 2025/07/08 17:25:57 by marioro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/parse_map.c src/utils.c
INC = -Iincludes

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re
