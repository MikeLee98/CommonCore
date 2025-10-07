/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:21:01 by mario             #+#    #+#             */
/*   Updated: 2025/09/30 17:33:50 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int max = find_max_index(*b);
        int pos = position_in_stack(*b, max);
        int size = stack_size(*b);

        if (pos <= size / 2)
            while ((*b)->index != max)
                rb(b);
        else
            while ((*b)->index != max)
                rrb(b);
        pa(a, b);
    }
}

void sort_chunks(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int chunk_size = get_chunk_size(size);
    int limit = chunk_size;
    int pushed = 0;

    while (*a)
    {
        if ((*a)->index < limit)
        {
            pb(a, b);
            pushed++;
            if (pushed == limit)
                limit += chunk_size;
        }
        else
            ra(a);
    }
    push_back_to_a(a, b);
}
