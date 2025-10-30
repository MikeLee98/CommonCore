/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:58:17 by mario             #+#    #+#             */
/*   Updated: 2025/10/30 02:22:36 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fill_stack_a(char	*str, t_stack	**a)
{
	char	**split;
	int		i;
	int		num;

	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		error_exit(a);
	while (split[i])
	{
		num = ft_atoi(split[i++]);
		add_back(a, new_node((int)num));
	}
	free_split(split);
}

static t_stack	*build_stack_a(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (parse_args(argv[i]))
			error_exit(&a);
		fill_stack_a(argv[i], &a);
		i++;
	}
	if (has_duplicates(a))
		error_exit(&a);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);
	a = build_stack_a(argc, argv);
	assign_indexes(a);
	b = NULL;
	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 5)
		sort_five(&a, &b);
	else
		sort_chunks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
