/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:05:40 by mario             #+#    #+#             */
/*   Updated: 2025/05/14 22:40:25 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sort_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args,char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned long), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned long), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		printvalue;

	va_start(args, format);
	i = -1;
	count = 0;
	if (!format)
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			printvalue = sort_format(format[++i], args);
			if (printvalue < 0)
				return (printvalue);
			count += printvalue;
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
