/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:44 by marioro2          #+#    #+#             */
/*   Updated: 2025/07/08 16:15:19 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_game
{
    char    **map;
    int     width;
    int     height;
} t_game;

// parsing
int		parse_map(t_game *game, char *file);

// utils
void	free_map(char **map);
void	print_error(char *msg);
char	*get_next_line(int fd);
char    *strjoin_gnl(char *s1, char *s2);
char    **ft_split(char const *s, char c);

#endif
