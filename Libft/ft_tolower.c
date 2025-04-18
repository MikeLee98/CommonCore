/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:55 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/14 16:23:21 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c | 0b00100000);
	return (c);
}

// int	main()
// {
// 	int c = 'A';
// 	printf("%c", ft_tolower(c));
// }
