/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:30 by marioro2          #+#    #+#             */
/*   Updated: 2025/11/21 04:59:25 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_env(t_env *env)
{
    while (env)
    {
        printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_env *env;

    env = init_env(envp);
    // later: export, unset, execve conversions, etc...
	print_env(env);
	return (0);
}
