/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:00:53 by mario             #+#    #+#             */
/*   Updated: 2025/11/03 18:48:18 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>

# include "../libft/libft.h"

/* utils.c */
void	ft_error(char *msg);
void	send_char(pid_t pid, char c);
void	send_message(pid_t pid, char *msg);

#endif
