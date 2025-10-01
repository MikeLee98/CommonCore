/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:58:17 by mario             #+#    #+#             */
/*   Updated: 2025/09/30 17:30:58 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *a;
	t_stack *b;
    t_stack *tmp;
	int size;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	assign_indices(a);
	b = NULL;
	size = stack_size(a);
	if (size == 2)
    	sort_two(&a);
	else if (size == 3)
    	sort_three(&a);
	else if (size == 5)
    	sort_five(&a, &b);
	else
    	sort_chunks(&a, &b);
    tmp = a;
    while (tmp)
    {
        printf("value: %d | index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    free_stack(&a);
	free_stack(&b);
    return (0);
}
