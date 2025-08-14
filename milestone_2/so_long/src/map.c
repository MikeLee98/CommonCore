/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:15:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/08/12 18:36:34 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	map_line_count(const char *filename)
{
	int		fd;
	int		count;
	char	*line;
	
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		{
			exit_error("Error opening file");
			return (-1);
		}
	while ((line = ft_get_next_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}	

int	read_map(const char *filename, t_game *game)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	game->height = map_line_count(filename);
	if (game->height == 0)
		exit_error("Empty map");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening file");
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		exit_error("Memory allocation failed");
	while ((line = ft_get_next_line(fd)))
	{
		remove_newline(line);
		game->map[row++] = line;
	}
	game->map[row] = NULL;
	close(fd);
	game->width = ft_strlen(game->map[0]);
	return (0);
}

void	validate_map(t_game *game)
{
	int i;
	int player;
	int exit;
	int collectibles;
	int line_len;
	
	i = 0;
	player = 0;
	exit = 0;
	collectibles = 0;
	line_len = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i])!= line_len)
			exit_error("Map is not rectangular");
		validate_line(game->map[i], i, game, &player, &exit, &collectibles);
		i++;	
	}
	if (player != 1)
		exit_error("Invalid number of players");
	if (exit != 1)
		exit_error("Invalid number of exits");
	if (collectibles < 1)
		exit_error("No collectibles found");
	game->collectibles = collectibles;
}

void	validate_line(char *line, int row, t_game *game, int *player, int *exit, int *collectibles) // !!!!!
{
	int		i;
	char	c;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		c = line[i];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			exit_error("Invalid character in map");
		if ((row == 0 || row == game->height - 1 || i == 0 || i == (int)ft_strlen(line) - 1) && c != '1')
			exit_error("Map is not surrounded by walls");
		if (c == 'P')
		{
			(*player)++;
			game->player_x = i;
			game->player_y = row; 
		}
		else if (c == 'E')
			(*exit)++;
		else if (c == 'C')
			(*collectibles)++;
		i++;
	}
}

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
