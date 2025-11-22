/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:59:57 by mario             #+#    #+#             */
/*   Updated: 2025/11/21 19:00:00 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

t_env   *init_env(char **envp);
void    env_add_back(t_env **env, t_env *new);
t_env   *env_new(char *str);
char    *extract_value(char *str);
char    *extract_key(char *str);

#endif
