/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stacking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 08:06:56 by mario             #+#    #+#             */
/*   Updated: 2025/10/30 02:24:48 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	indexing(t_stack *stack, int *arr, int size)
{
	t_stack	*tmp;
	int		j;

	tmp = stack;
	while (tmp)
	{
		j = 0;
		while (j < size)
		{
			if (tmp->value == arr[j])
			{
				tmp->index = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
}

static void	fill_array(t_stack *stack, int *arr)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*tmp;
	int		*arr;
	int		size;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit(&stack);
	fill_array(stack, arr);
	sort_array(arr, size);
	indexing(stack, arr, size);
	free(arr);
}
