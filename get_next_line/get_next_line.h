/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:50:19 by mario             #+#    #+#             */
/*   Updated: 2025/05/25 05:05:07 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
static size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int	check_newline(char *buffer);
void	read_to_buffer(int fd, char **line, char *buffer);
void	trim_buffer(char *buffer);

#endif
