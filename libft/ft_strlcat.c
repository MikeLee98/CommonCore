/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:54:05 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/23 01:27:57 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (src_len + size);
	if (src_len < size - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
	dst[size - 1] = 0;
	return (dst_len + src_len);
}

// int main() 
// {
//     char buffer0[4] = "dst\0";
//     size_t result0 = ft_strlcat("dst", "src", 0);
// 	printf("Resultado: %s\n", buffer0);
//     printf("Comprimento total pretendido: %zu\n", result0);
	
// 	char buffer1[5] = "dst";
// 	size_t result1 = ft_strlcat(buffer1, "src", 1);
// 	printf("Resultado: %s\n", buffer1);
//     printf("Comprimento total pretendido: %zu\n", result1);
	
// 	char buffer2[6] = "dst";
// 	size_t result2 = ft_strlcat(buffer2, "src", 2);
// 	printf("Resultado: %s\n", buffer2);
//     printf("Comprimento total pretendido: %zu\n", result2);

// 	char buffer3[7] = "dst";
// 	size_t result3 = ft_strlcat(buffer3, "src", 3);
// 	printf("Resultado: %s\n", buffer3);
//     printf("Comprimento total pretendido: %zu\n", result3);
	
// 	char buffer4[8] = "dst";
// 	size_t result4 = ft_strlcat(buffer4, "src", 4);
// 	printf("Resultado: %s\n", buffer4);
//     printf("Comprimento total pretendido: %zu\n", result4);

// 	char buffer5[9] = "dst";
// 	size_t result5 = ft_strlcat(buffer5, "src", 5);
// 	printf("Resultado: %s\n", buffer5);
//     printf("Comprimento total pretendido: %zu\n", result5);

// 	char buffer6[10] = "dst";
// 	size_t result6 = ft_strlcat(buffer6, "src", 6);
// 	printf("Resultado: %s\n", buffer6);
//     printf("Comprimento total pretendido: %zu\n", result6);
	
// 	char buffer7[11] = "dst";
// 	size_t result7 = ft_strlcat(buffer7, "src", 7);
// 	printf("Resultado: %s\n", buffer7);
//     printf("Comprimento total pretendido: %zu\n", result7);

// 	char buffer8[12] = "dst";
// 	size_t result8 = ft_strlcat(buffer8, "src", 8);
// 	printf("Resultado: %s\n", buffer8);
//     printf("Comprimento total pretendido: %zu\n", result8);
// }
