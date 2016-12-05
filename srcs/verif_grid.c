/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:30:44 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/05 13:38:59 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int     check_c(char *str, char c)
{
    int i;
	int len;

    i = 0;
	len = 0;
    if (str == NULL)
        return (0);
    while (str[len])
    {
		if (str[len] == c)
			i++;
		len++;
    }
    return (i);
}

int     ft_check_grid(char **str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != NULL)
    {
        if (check_c(str[i], '.') == 12)
            i++;
        else
            return (0);
    }
    if (str[i] == NULL)
        return (1);
    return (0);
}
