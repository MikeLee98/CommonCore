/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:46:25 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/16 11:08:24 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*chr;

	chr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			chr = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
