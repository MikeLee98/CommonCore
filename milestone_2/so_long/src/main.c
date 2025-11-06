/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:13 by marioro2          #+#    #+#             */
/*   Updated: 2025/11/06 18:52:02 by marioro2         ###   ########.fr       */
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

static int	check_extension(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return (ft_strncmp(str + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("Use: ./so_long map.ber");
	if (!check_extension(argv[1]))
		exit_error("File must be .ber");
	read_map(argv[1], &game);
	validate_map(&game);
	validate_path(&game);
	game.moves = 0;
	init_game(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	printf("Valid map! Size: %d x %d\n", game.width, game.height);
	return (0);
}
