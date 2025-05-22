/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:50:06 by mario             #+#    #+#             */
/*   Updated: 2025/05/22 03:04:03 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_get_line(char *buf, int size, int fd)
{
	int i = 0;
	char c;
	ssize_t bytes_read;

	if (size <= 0 || !buf)
		return NULL;

	while (i < size - 1)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read <= 0)
			break;
		buf[i++] = c;
		if (c == '\n')
			break;
	}
	buf[i] = '\0';
	if (i == 0 && bytes_read <= 0)
		return NULL;
	return buf;
}

int main(void)
{
	char buffer[10];
	int	fd = open("text.txt", O_RDONLY);
	while (ft_get_line(buffer, sizeof(buffer), fd) != NULL)
		printf("%s", buffer);
	return 0;
}
