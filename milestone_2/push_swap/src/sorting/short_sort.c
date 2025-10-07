/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:35:22 by mario             #+#    #+#             */
/*   Updated: 2025/09/30 17:33:53 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int find_min_index(t_stack *a)
{
	int min_index;

	min_index = a->index;
	while (a)
	{
		if (a->index < min_index)
			min_index = a->index;
		a = a->next;
	}
	return (min_index);
}

static void push_min_to_b(t_stack **a, t_stack **b)
{
	int min_index;
	t_stack *tmp;
	int pos;
	int size;
	
	min_index = find_min_index(*a);
	tmp = *a;
	pos = 0;
	size = 0;
	while (tmp)
	{
		if (tmp->index == min_index)
			break ;
		pos++;
		tmp = tmp->next;
	}
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

void sort_five(t_stack **a, t_stack **b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
