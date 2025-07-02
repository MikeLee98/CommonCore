/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:27:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/24 14:07:23 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	// while (n-- && (*s1 || *s2))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// int main()
// {
// 	char *str1 = "hel";
// 	char *str2 = "hel";
// 	char *str3 = "world";

// 	printf("Comparing '%s' and '%s': %d\n", str1, str2, strncmp(str1, str2, 3));
// 	printf("Comparing '%s' and '%s': %d\n", str1, str3, strncmp(str1, str3, 9));
// 	printf("Comparing '%s' and '%s': %d\n", str1, "", strncmp(str1, "", 5));

// 	printf("Comparing '%s' and '%s': %d\n", str1, str2, ft_strncmp(str1, str2, 3));
// 	printf("Comparing '%s' and '%s': %d\n", str1, str3, ft_strncmp(str1, str3, 9));
// 	printf("Comparing '%s' and '%s': %d\n", str1, "", ft_strncmp(str1, "", 5));
// 	return 0;
// }
