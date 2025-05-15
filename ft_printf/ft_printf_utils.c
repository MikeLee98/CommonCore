/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:55:19 by mario             #+#    #+#             */
/*   Updated: 2025/05/14 19:32:58 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	ft_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		return (write(1, "-", 1) + ft_putnbr(-nb));
	}
	if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	c = nb + '0';
	return (write(1, &c, 1));
}

int	ft_putunsigned(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	c = nb + '0';
	return (write(1, &c, 1));
}

int	ft_puthex(unsigned long n, int upper)
{
	char	*base;
	char	c;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		return (ft_puthex(n / 16, upper) + ft_puthex(n % 16, upper));
	c = base[n % 16];
	return (write(1, &c, 1));
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_puthex((unsigned long)ptr, 0));
}
