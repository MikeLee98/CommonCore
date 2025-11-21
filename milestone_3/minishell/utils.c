/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 03:57:55 by mario             #+#    #+#             */
/*   Updated: 2025/11/21 03:57:59 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *extract_key(char *str)
{
    int     i;

    i = 0;
    while (str[i] && str[i] != '=')
        i++;
    return (ft_substr(str, 0, i));
}

char    *extract_value(char *str)
{
    int     i;

    i = 0;
    while (str[i] && str[i] != '=')
        i++;
    if (str[i] == '=')
        return (ft_strdup(str + i + 1));
    return (NULL);
}
