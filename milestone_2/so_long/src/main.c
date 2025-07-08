/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:13 by marioro2          #+#    #+#             */
/*   Updated: 2025/07/08 17:30:04 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int	main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
		print_error("");

	parse_map(&game, argv[1]);
	
	// temporario
	for (int i = 0; game.map[i]; i++)
		printf("%s\n", game.map[i]);

	free_map(game.map);
	return (0);
}
