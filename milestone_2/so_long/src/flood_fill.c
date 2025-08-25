/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:01:22 by mario             #+#    #+#             */
/*   Updated: 2025/08/15 16:06:45 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_flood *data)
{
	char	c;

	if(y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	c = map[y][x];
	if (c == '1' || c == 'X')
		return ;
	if (c == 'C')
		(*data->collects)++;
	if (c == 'E')
		*data->exit_found = 1;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

void 	validate_path(t_game *game)
{
	char	**visited;
	int		collects;
	int		exit_found;
	t_flood	data;

	visited = copy_map(game->map, game->height);
	if (!visited)
		exit_error("Error copying map");
	collects = 0;
	exit_found = 0;
	data.collects = &collects;
	data.exit_found = &exit_found;
	flood_fill(visited, game->player_x, game->player_y, &data);
	free_map(visited);
	if (collects != game->collectibles)
		exit_error("Collectibles not reachable");
	if (!exit_found)
		exit_error("Exit not reachable");
}
