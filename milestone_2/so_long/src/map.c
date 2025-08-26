/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:15:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/08/26 22:22:29 by mario            ###   ########.fr       */
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
			exit_error("Error opening file", NULL);
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
		exit_error("Empty map", NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening file", NULL);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		exit_error("Memory allocation failed", NULL);
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
	int line_len;
	
	i = 0;
	game->player = 0;
	game->exit = 0;
	game->collectibles = 0;
	line_len = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != line_len)
			exit_error("Map is not rectangular", game);
		validate_line(game->map[i], i, game);
		i++;	
	}
	if (game->player != 1)
		exit_error("Invalid number of players", game);
	if (game->exit != 1)
		exit_error("Invalid number of exits", game);
	if (game->collectibles < 1)
		exit_error("No collectibles found", game);
}

void	validate_line(char *line, int row, t_game *game)
{
	int		i;
	int		last_indx;
	char	c;

	last_indx = ft_strlen(line) - 1;
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			exit_error("Invalid character in map", game);
		check_wall(row, i, last_indx, c);
		if (c == 'P')
		{
			(game->player)++;
			game->player_x = i;
			game->player_y = row;
			game->map[row][i] = '0';
		}
		else if (c == 'E')
			(game->exit)++;
		else if (c == 'C')
			(game->collectibles)++;
		i++;
	}
}

void	check_wall(int row, int col, int last_idx, char c)
{
	if ((row == 0 || row == last_idx || col == 0 || col == last_idx) && c != '1')
		exit_error("Map is not surrounded by walls", NULL);
}
