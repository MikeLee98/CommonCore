/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:50:19 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/21 11:15:57 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)ptr;
	while (n-- > 0)
		*(tmp_ptr++) = '\0';
}

// int	main()
// {
// 	char	s[] = "hello world";
// 	ft_bzero(s, 5);
// }
