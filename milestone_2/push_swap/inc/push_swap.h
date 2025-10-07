/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:43:44 by mario             #+#    #+#             */
/*   Updated: 2025/10/07 12:10:46 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// main
int		main(int argc, char **argv);

// parsing
t_stack	*parse_args(int argc, char **argv);

//stack_utils
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);
int stack_size(t_stack *a);

// index_stacking
void	assign_indices(t_stack *stack);

// swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// short_sort
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);

// chunk_utils
int  get_chunk_size(int size);
int  position_in_stack(t_stack *stack, int index);
int  find_max_index(t_stack *stack);

//sort_chunks
void sort_chunks(t_stack **a, t_stack **b);

// error
void	error_exit(t_stack **stack_a);

#endif
