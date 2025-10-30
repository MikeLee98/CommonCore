/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:15:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/10/30 16:13:29 by marioro2         ###   ########.fr       */
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
		exit_error("Error opening file");
	line = ft_get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	count_elements(char c, t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	validate_line(char *line, int row, t_game *game)
{
	int		col;
	char	c;

	col = 0;
	while (line[col])
	{
		c = line[col];
		if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			exit_error("Invalid character in map");
		check_wall(game, row, col, c);
		if (c == 'P')
		{
			game->player_x = col;
			game->player_y = row;
		}
		else if (c == 'C')
			(game->collectibles)++;
		col++;
	}
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
	line = ft_get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		game->map[row++] = line;
		line = ft_get_next_line(fd);
	}
	game->map[row] = NULL;
	close(fd);
	game->width = ft_strlen(game->map[0]);
	return (0);
}

void	validate_map(t_game *game)
{
	int	i;
	int	line_len;

	i = 0;
	game->player = count_elements('P', game);
	game->exit = count_elements('E', game);
	if (game->player != 1)
		exit_error("Invalid number of players");
	if (game->exit != 1)
		exit_error("Invalid number of exits");
	game->collectibles = 0;
	line_len = ft_strlen(game->map[0]);
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != line_len)
			exit_error("Map is not rectangular");
		validate_line(game->map[i], i, game);
		i++;
	}
	if (game->collectibles < 1)
		exit_error("No collectibles found");
}
