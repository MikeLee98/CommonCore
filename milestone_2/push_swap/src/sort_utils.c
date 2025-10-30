/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:55:15 by mario             #+#    #+#             */
/*   Updated: 2025/10/30 04:10:41 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	find_min_index(t_stack *a)
{
	int	min_index;

	min_index = a->index;
	while (a)
	{
		if (a->index < min_index)
			min_index = a->index;
		a = a->next;
	}
	return (min_index);
}

static int	find_position(t_stack **a, int min_index)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == min_index)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min_index;
	int		pos;
	int		size;

	min_index = find_min_index(*a);
	pos = find_position(a, min_index);
	size = 0;
	tmp = *a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while ((*a)->index != min_index)
			ra(a);
	else
		while ((*a)->index != min_index)
			rra(a);
	pb(a, b);
}
