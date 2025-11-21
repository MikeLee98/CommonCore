/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:58:21 by mario             #+#    #+#             */
/*   Updated: 2025/11/21 04:28:41 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env   *env_new(char *str)
{
    t_env   *node;

    node = malloc(sizeof(t_env));
    if (!node)
        return (NULL);
    node->key = extract_key(str);
    node->value = extract_value(str);
    node->next = NULL;
    return (node);
}

void    env_add_back(t_env **env, t_env *new)
{
    t_env   *tmp;

    if (!*env)
    {
        *env = new;
        return ;
    }
    tmp = *env;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

t_env   *init_env(char **envp)
{
    t_env   *env;
    int     i;

    env = NULL;
    i = 0;
    while (envp[i])
    {
        env_add_back(&env, env_new(envp[i]));
        i++;
    }
    return (env);
}
