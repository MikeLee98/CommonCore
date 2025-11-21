/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:54:44 by marioro2          #+#    #+#             */
/*   Updated: 2025/11/21 04:00:14 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

#endif
