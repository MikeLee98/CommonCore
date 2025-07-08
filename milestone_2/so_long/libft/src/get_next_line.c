/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:49:51 by mario             #+#    #+#             */
/*   Updated: 2025/05/26 17:32:05 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	line = NULL;
	read_to_buffer(fd, &line, buffer);
	if (line)
	{
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i] == '\n')
			i++;
		line[i] = '\0';
	}
	trim_buffer(buffer);
	return (line);
}

// int	main()
// {
// 	int		fd = open ("get_next_line.h", O_RDONLY);
// 	char	*line;

// 	line = NULL;
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	// while ((line = get_next_line(fd)))
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// }
// 	close(fd);
// }
