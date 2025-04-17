/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:07:10 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/16 18:17:36 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	const unsigned char	*str;
	size_t	i;

	cpy = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (cpy < str || cpy >= str + n)
	{
		i = 0;
		while (i < n)
		{
			cpy[i] = str[i];
			i++;
		}
	}
	else 
	{
		i = n;
		while (i > 0)
		{
			cpy[i - 1] = str[i - 1];
			i--;
		}
	}
	return (dest);
}

// char *createstr(char * str)
// {
// 	int len = strlen(str);
// 	char * retval = malloc(len + 1);
// 	int i = 0;
// 	while(str[i] != '\0')
// 	{
// 		retval[i] = str[i];
// 		i++;
// 	}
// 	retval[i] = '\0';
// 	return retval;

// }
// void test(void *(*func)(void *, const void *, size_t ))
// {
// 	char	*dest;
// 	char	*src;
// 	char *str = "hello world!";
// 	char *str2 = createstr(str);
// 	int len = strlen(str);
// 	src  = &(str2[0]);
// 	dest = &(src[1]);
	
// 	printf("src (%s)\n", src);
// 	printf("dest (%s)\n", dest);
// 	printf("result (%s)\n\n", (char *)func(dest, src, len));
// 	free(str2);
// }
// int	main()
// {
// 	printf("Base func\n");
// 	test(memmove);
// 	printf("My func\n");

// 	test(ft_memmove);
	
// }
