/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:21:01 by mario             #+#    #+#             */
/*   Updated: 2025/10/30 04:11:35 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max_index(*b);
		pos = position_in_stack(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
			while ((*b)->index != max)
				rb(b);
		else
			while ((*b)->index != max)
				rrb(b);
		pa(a, b);
	}
}

static void	push_to_b(t_stack **a, t_stack **b, int start, int size)
{
	int	pushed;
	int	chunk_size;
	int	window_end;

	chunk_size = get_chunk_size(size);
	while (start < size)
	{
		window_end = start + 2 * chunk_size;
		if (window_end > size)
			window_end = size;
		pushed = 0;
		while (pushed < (window_end - start) && *a)
		{
			if ((*a)->index >= start && (*a)->index < window_end)
			{
				pb(a, b);
				if ((*b)->index >= start + chunk_size)
					rb(b);
				pushed++;
			}
			else
				ra(a);
		}
		start = start + 2 * chunk_size;
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	int	size;
	int	start;

	size = stack_size(*a);
	start = 0;
	push_to_b(a, b, start, size);
	push_back_to_a(a, b);
}
