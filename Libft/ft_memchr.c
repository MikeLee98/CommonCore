/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:51:53 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/16 17:15:59 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str;

	str = (const unsigned char *)s;
	while (str || n > 0)
	{
		if (*str == (char)c)
			return ((void *)str);
		str++;
		n--;
	}
	if ((char)c == '\0')
		return ((void *)str);
	str = NULL;
	return ((void *)str);
}
