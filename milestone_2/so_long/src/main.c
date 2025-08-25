/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:13 by marioro2          #+#    #+#             */
/*   Updated: 2025/08/25 22:22:51 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("Use: ./so_long mapa.ber");
	read_map(argv[1], &game);
	validate_map(&game);
	validate_path(&game);
	init_game(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	printf("Mapa válido! Dimensões: %d x %d\n", game.width, game.height);
	return (0);
}
