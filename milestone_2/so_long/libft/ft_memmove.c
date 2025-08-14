/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:07:10 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/23 01:27:37 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	const unsigned char	*tmp_src;

	if (!dst && !src && n > 0)
		return (NULL);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_dst > tmp_src)
		while (n--)
			tmp_dst[n] = tmp_src[n];
	else
		ft_memcpy(tmp_dst, tmp_src, n);
	return (dst);
}

// // Função auxiliar para imprimir arrays de bytes
// void	print_bytes(const char *label, unsigned char *data, size_t n)
// {
// 	printf("%s: \"", label);
// 	for (size_t i = 0; i < n; i++)
// 		printf("%c", data[i] ? data[i] : '.');
// 	printf("\"\n");
// }

// // Função para testar e comparar
// void	test_case(const char *desc, void *(*f)(void *, const void *, size_t), void *dst, const void *src, size_t n)
// {
// 	printf("== %s ==\n", desc);
// 	unsigned char *ref = malloc(n);
// 	unsigned char *res = malloc(n);
// 	memcpy(ref, dst, n);
// 	memcpy(res, dst, n);

// 	memmove(ref, src, n);
// 	f(res, src, n);

// 	print_bytes("memmove", ref, n);
// 	print_bytes("ft_memmove", res, n);

// 	if (memcmp(ref, res, n) == 0)
// 		printf("✅ Resultados iguais\n\n");
// 	else
// 		printf("❌ Resultados diferentes\n\n");

// 	free(ref);
// 	free(res);
// }

// int	main(void)
// {
// 	// Caso normal
// 	char buffer1[] = "abcdefgh";
// 	char buffer2[] = "abcdefgh";
// 	test_case("Cópia normal", ft_memmove, buffer2, buffer2 + 2, 4);

// 	// Sobreposição: dst > src
// 	char overlap1[] = "123456789";
// 	char overlap2[] = "123456789";
// 	test_case("Sobreposição dst > src", ft_memmove, overlap2 + 2, overlap2, 5);

// 	// Sobreposição: src > dst
// 	char overlap3[] = "abcdefghi";
// 	char overlap4[] = "abcdefghi";
// 	test_case("Sobreposição src > dst", ft_memmove, overlap4, overlap4 + 2, 5);

// 	// n = 0
// 	char zero1[] = "aaaaaaa";
// 	char zero2[] = "aaaaaaa";
// 	test_case("Tamanho zero", ft_memmove, zero2, zero2 + 3, 0);

// 	// Ponteiros NULL e n = 0
// 	printf("== NULL com size 0 ==\n");
// 	void *ret1 = memmove(NULL, NULL, 0);
// 	void *ret2 = ft_memmove(NULL, NULL, 0);
// 	printf("memmove:   %p\n", ret1);
// 	printf("ft_memmove: %p\n", ret2);
// 	if (ret1 == ret2)
// 		printf("✅ Igual comportamento\n\n");
// 	else
// 		printf("❌ Diferente\n\n");

// 	// Ponteiros NULL com n > 0 (comportamento indefinido, deve evitar)
// 	printf("== NULL com size > 0 (espera-se crash) ==\n");
// 	// Descomentar para testar (pode crashar)
// 	/*
// 	memmove(NULL, NULL, 4);
// 	ft_memmove(NULL, NULL, 4);
// 	*/

// 	return 0;
// }
