/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stacking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 08:06:56 by mario             #+#    #+#             */
/*   Updated: 2025/09/27 16:19:58 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void sort_array(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void assign_indices(t_stack *stack)
{
	t_stack *tmp;
	int *arr;
	int size;
	int i;
	int j;

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
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, size);
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
	free(arr);
}


