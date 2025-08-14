/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:33:54 by mario             #+#    #+#             */
/*   Updated: 2025/08/12 18:34:07 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void 	validate_path(t_game *game)
{
	char	**visited;
	int		collects;
	int		exit_found;

	visited = copy_map(game->map, game->height);
	if (!visited)
		exit_error("Error copying map");
	collects = 0;
	exit_found = 0;
	flood_fill(visited, game->player_x, game->player_y, &(t_flood){&collects, &exit_found}); // !!!!!
	free_map(visited);
	if (collects != game->collectibles)
		exit_error("Collectibles not reachable");
	if (!exit_found)
		exit_error("Exit not reachable");
}