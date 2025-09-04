/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:55 by marioro2          #+#    #+#             */
/*   Updated: 2025/04/23 20:17:02 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c | 0x20);
	return (c);
}

// int	main()
// {
// 	int c = 'A';
// 	printf("%c", ft_tolower(c));
// }


// int main() {
// 	// Teste com letras maiúsculas
//     printf("ft_tolower('A') = %c, tolower('A') = %c\n", ft_tolower('A'), tolower('A'));  // Esperado: 'a'
//     printf("ft_tolower('Z') = %c, tolower('Z') = %c\n", ft_tolower('Z'), tolower('Z'));  // Esperado: 'z'

//     // Teste com letras minúsculas (não deve mudar)
//     printf("ft_tolower('a') = %c, tolower('a') = %c\n", ft_tolower('a'), tolower('a'));  // Esperado: 'a'
//     printf("ft_tolower('z') = %c, tolower('z') = %c\n", ft_tolower('z'), tolower('z'));  // Esperado: 'z'

//     // Teste com caracteres não alfabéticos
//     printf("ft_tolower('1') = %c, tolower('1') = %c\n", ft_tolower('1'), tolower('1'));  // Esperado: '1' (não muda)
//     printf("ft_tolower('@') = %c, tolower('@') = %c\n", ft_tolower('@'), tolower('@'));  // Esperado: '@' (não muda)
//     printf("ft_tolower(' ') = %c, tolower(' ') = %c\n", ft_tolower(' '), tolower(' '));  // Esperado: ' ' (não muda)
//     printf("ft_tolower('!') = %c, tolower('!') = %c\n", ft_tolower('!'), tolower('!'));  // Esperado: '!' (não muda)

//     // Teste com caracteres fora do intervalo de letras
//     printf("ft_tolower(65) = %c, tolower(65) = %c\n", ft_tolower(65), tolower(65));   // Esperado: 'a' (65 = 'A')
//     printf("ft_tolower(90) = %c, tolower(90) = %c\n", ft_tolower(90), tolower(90));   // Esperado: 'z' (90 = 'Z')
//     printf("ft_tolower(123) = %c, tolower(123) = %c\n", ft_tolower(123), tolower(123)); // Esperado: '{' (não muda)
//     return 0;
// }