/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:44 by marioro2          #+#    #+#             */
/*   Updated: 2025/08/12 18:51:51 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
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
	int     player_x;
	int     player_y;
	int     player;
	int     exits;
	int     collectibles;
	int     moves;
} t_game;

typedef struct s_flood
{
	int	*collects;
	int	*exit_found;
}	t_flood;

// parsing
int		read_map(const char *filename, t_game *game);
void	exit_error(const char *msg);
void	validate_map(t_game *game);
void	validate_line(char *line, int row, t_game *game, int *player, int *exit, int *collectibles);
void	validate_path(t_game *game);

// utils
void	free_map(char **map);
void	print_error(char *msg);
char	*get_next_line(int fd);
char    *gnl_strjoin(char *s1, char *s2);
char    **ft_split(char const *s, char c);
void	flood_fill(char **map, int x, int y, t_flood *data);
char	**copy_map(char **map, int height);
void	free_map(char **map);
void	remove_newline(char *line);

#endif
