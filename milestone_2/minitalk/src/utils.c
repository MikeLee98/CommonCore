/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:01:45 by mario             #+#    #+#             */
/*   Updated: 2025/11/14 04:22:33 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i--;
	}
}

// void	send_message(pid_t pid, char *msg)
// {
// 	int	i;

// 	i = 0;
// 	while (msg[i])
// 	{
// 		send_char(pid, msg[i]);
// 		i++;
// 	}
// }
