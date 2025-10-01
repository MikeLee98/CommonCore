/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:24:19 by mario             #+#    #+#             */
/*   Updated: 2025/09/28 18:05:46 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
