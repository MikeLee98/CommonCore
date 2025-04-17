/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:23:10 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/17 16:41:16 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return (char *)big;
	while (big[i] && i < len)
	{
		while (little[i] && i + j < len)
		{
			if (big[i + j] != little[j])
				break;
			j++;
		}
		i++;
		if (little[j] == '\0')
			return ((char *)(big + i));
	}
	return (NULL);
}
