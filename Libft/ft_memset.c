/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:54:05 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/14 14:27:19 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t i;

	str = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

// int	main()
// {
// 	char	s[] = "hello world";
// ft_memset(s, 97, 5)
// 	printf("%s", (str);
// }
