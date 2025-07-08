/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:10:40 by marioro2          #+#    #+#             */
/*   Updated: 2025/07/08 17:20:21 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, strlen(msg));
	exit(1);
}

void	free_map(char **map)
{
	int i = 0;
	
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}
