/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:07:10 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/21 18:31:33 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	const unsigned char	*tmp_src;
	size_t	i;

	if (!dst && !src)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (tmp_dst > tmp_src)
		while (n-- > 0)
			tmp_dst[n] = tmp_src[n];
	else 
		while (i++ < n)
			tmp_dst[i] = tmp_src[i];
	return (dst);
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
// 	dest = &(src[2]);
	
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
