/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:29:18 by mario             #+#    #+#             */
/*   Updated: 2025/09/27 08:04:34 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	long	num;
	int		i;
	
	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit(&a);
		num = ft_atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
			error_exit(&a);
		add_back(&a, new_node((int)num));
		i++;
	}
	if (has_duplicates(a))
		error_exit(&a);
	return (a);
}
