/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:30 by marioro2          #+#    #+#             */
/*   Updated: 2025/11/18 18:59:20 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *input;
	
	while(1)
	{
		input = readline("minishell$>");
		parser(input);
		free(input);
	}
}
