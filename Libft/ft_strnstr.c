/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:23:10 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/17 16:21:20 by marioro2         ###   ########.fr       */
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

char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t i, j;

    // Se a agulha for vazia, devolve o próprio haystack
    if (*needle == '\0')
        return (char *)haystack;

    for (i = 0; haystack[i] != '\0' && i < len; i++) {
        // Só tentamos comparar se ainda houver espaço suficiente
        for (j = 0; needle[j] != '\0' && i + j < len; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (needle[j] == '\0')
            return (char *)(haystack + i); // Encontrou
    }

    return NULL; // Não encontrou
}
