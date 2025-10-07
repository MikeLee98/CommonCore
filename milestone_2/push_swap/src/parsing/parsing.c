/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:29:18 by mario             #+#    #+#             */
/*   Updated: 2025/10/07 12:09:49 by mario            ###   ########.fr       */
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

static int	is_number(char *str)
{
	int i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int has_duplicates(t_stack *stack)
{
    t_stack *i;
    t_stack *j;

    i = stack;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->value == j->value)
                return (1);
            j = j->next;
        }
        i = i->next;
    }
    return (0);
}
