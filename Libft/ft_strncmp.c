/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:27:37 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/16 18:09:02 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int main()
{
char str1[] = "helo";
char str2[] = "hel";
char str3[] = "world";

printf("Comparing '%s' and '%s': %d\n", str1, str2, ft_strncmp(str1, str2, 4));

printf("Comparing '%s' and '%s': %d\n", str1, str3, ft_strncmp(str1, str3, 9));

printf("Comparing '%s' and '%s': %d\n", str1, "", ft_strncmp(str1, "", 5));

printf("Comparing '%s' and '%s': %d\n", str1, str2, strncmp(str1, str2, 4));

printf("Comparing '%s' and '%s': %d\n", str1, str3, strncmp(str1, str3, 9));

printf("Comparing '%s' and '%s': %d\n", str1, "", strncmp(str1, "", 5));
return 0;
}
