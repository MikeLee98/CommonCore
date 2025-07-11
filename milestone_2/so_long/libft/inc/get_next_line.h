/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:50:19 by mario             #+#    #+#             */
/*   Updated: 2025/07/08 17:35:46 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
char			*strjoin_gnl(char *s1, char const *s2);
int				check_newline(char *buffer);
void			read_to_buffer(int fd, char **line, char *buffer);
void			trim_buffer(char *buffer);

#endif
