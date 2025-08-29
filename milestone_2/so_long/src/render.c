/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:50:03 by mario             #+#    #+#             */
/*   Updated: 2025/08/29 17:25:17 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define TILE_SIZE 64

void	load_images(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &img_w, &img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &img_w, &img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &img_w, &img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &img_w, &img_h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &img_w, &img_h);
	if (!game->img_wall
		|| !game->img_floor
		|| !game->img_player
		|| !game->img_exit
		|| !game->img_collectible)
	{
		free_game(game);
		exit_error("Missing image files");
	}
}

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_tile(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				draw_tile(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'E')
				draw_tile(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'C')
				draw_tile(game, game->img_collectible, x, y);
			x++;
		}
		y++;
	}
	draw_tile(game, game->img_player, game->player_x, game->player_y);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Failed to initialize MLX");
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error("Failed to create window");
	load_images(game);
	render_map(game);
}
