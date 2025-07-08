/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:44 by marioro2          #+#    #+#             */
/*   Updated: 2025/07/08 17:43:57 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_game
{
    char    **map;
    int     width;
    int     height;
} t_game;

// parsing
void	parse_map(t_game *game, char *filename);

// utils
void	free_map(char **map);
void	print_error(char *msg);
char	*get_next_line(int fd);
char    *gnl_strjoin(char *s1, char *s2);
char    **ft_split(char const *s, char c);

#endif
