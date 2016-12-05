/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:30:44 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/05 17:49:23 by dzheng           ###   ########.fr       */
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

int		check_end_line(char *str)
{
	int count;
	int len;

	count = 0;
	len = 4;
	if (str == NULL)
		return (0);
	while (str[len])
	{
		if (str[len] == '\n')
			count++;
		len = len + 5 ;
	}
	return (count);
}

int     ft_check_grid(char **str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i] != NULL)
    {
        if (check_c(str[i], '.') == 12 && check_c(str[i], '#') == 4 &&
			(check_end_line(str[i]) == 4 || check_end_line(str[i]) == 3))
            i++;
        else
            return (0);
    }
    if (str[i] == NULL)
        return (1);
    return (0);
}
