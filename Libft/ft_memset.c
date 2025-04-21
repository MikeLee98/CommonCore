/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:54:05 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/21 11:15:12 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)(ptr);
	while (n-- > 0)
		*(tmp_ptr++) = (unsigned char)c;
	return (ptr);
}

// int	main()
// {
// 	char	s[] = "hello world";
// ft_memset(s, 97, 5)
// 	printf("%s", (str);
// }
