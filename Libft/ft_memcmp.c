/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:16:03 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:39 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1 || str2) && n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
