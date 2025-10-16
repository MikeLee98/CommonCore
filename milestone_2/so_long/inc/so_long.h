/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:44 by marioro2          #+#    #+#             */
/*   Updated: 2025/10/16 20:06:02 by mario            ###   ########.fr       */
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
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player;
	int		exit;
	int		collectibles;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	int		moves;
}	t_game;

typedef struct s_flood
{
	int	*collects;
	int	*exit_found;
}	t_flood;

// map
int		read_map(const char *filename, t_game *game);
void	validate_map(t_game *game);

// flood fill
void	validate_path(t_game *game);

// render
void	init_game(t_game *game);
void	render_map(t_game *game);

// main
int		close_game(t_game *game);
int		handle_key(int keycode, t_game *game);

// move player
void	move_player(t_game *game, int dx, int dy);

// utils
void	exit_error(const char *msg);
void	free_map(char **map);
void	remove_newline(char *line);
void	free_game(t_game *game);
void	check_wall(t_game *game, int row, int col, char c);

#endif
