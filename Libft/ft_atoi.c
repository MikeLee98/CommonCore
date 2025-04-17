/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:42:12 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/17 17:05:58 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int nbr;
	int sign;
	
	nbr = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign = sign * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - 48);
		nptr++;
	}
	return (nbr * sign);
}

// int	main()
// {
// 	printf("%i\n", ft_atoi("     		\n-123abc 123abc"));
// 	printf("%i\n", ft_atoi("aaa-123"));
// 	printf("%i\n", ft_atoi("---123"));
// }
