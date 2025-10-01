# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 05:32:22 by mario             #+#    #+#              #
#    Updated: 2025/09/30 17:35:24 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc

CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
INCDIR = inc
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRC = $(SRCDIR)/main.c \
	  $(SRCDIR)/parsing.c \
	  $(SRCDIR)/parsing_utils.c \
	  $(SRCDIR)/stack_utils.c \
	  $(SRCDIR)/index_stacking.c \
	  $(SRCDIR)/swap.c \
	  $(SRCDIR)/push.c \
	  $(SRCDIR)/rotate.c \
	  $(SRCDIR)/reverse_rotate.c \
	  $(SRCDIR)/short_sort.c \
	  $(SRCDIR)/chunk_utils.c \
	  $(SRCDIR)/sort_chunks.c \
	  $(SRCDIR)/error.c
OBJ = $(SRC:.c=.o)
INC = -I $(INCDIR) -I $(LIBFTDIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
