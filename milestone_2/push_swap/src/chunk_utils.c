/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:16:09 by mario             #+#    #+#             */
/*   Updated: 2025/09/30 17:33:43 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int get_chunk_size(int size)
{
    if (size <= 100)
        return 20;
    return 45;
}

int position_in_stack(t_stack *stack, int index)
{
    int pos = 0;
    while (stack)
    {
        if (stack->index == index)
            return pos;
        pos++;
        stack = stack->next;
    }
    return -1;
}

int find_max_index(t_stack *stack)
{
    int max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}
