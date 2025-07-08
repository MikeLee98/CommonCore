/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:15:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/07/08 16:45:16 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *file)
{
	int len = strlen(file);
	return (len > 4 && strcmp(file + len - 4, ".ber") == 0);
}

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*full = NULL;

	if (!check_extension(filename))
		print_error("File extension must be .ber");
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Could not open the file");
	
	while ((line = get_next_line(fd)))
	{
		full = strjoin_gnl(full, line);
		free(line);
		game->height++;
	}
	close(fd);
	if (!full)
		print_error("Empty map");
	
	game->map = ft_split(full, '\n');
	free(full);

	game->width = strlen(game->map[0]);
}
