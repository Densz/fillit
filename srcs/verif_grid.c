/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:30:44 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/14 10:38:55 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char		**ft_put_letters(char **str)
{
	int		tetri;
	int		i;
	char	c;

	tetri = 0;
	c = 65;
	while (str[tetri])
	{
		i = 0;
		while (str[tetri][i] && c <= 'Z')
		{
			if (str[tetri][i] == '#')
				str[tetri][i] = c;
			i++;
		}
		tetri++;
		c++;
	}
	return (str);
}

int			check_link(char *str)
{
	int		i;
	int		count_d;

	i = 0;
	count_d = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count_d++;
			if (str[i + 5] == '#')
				count_d++;
			if (str[i - 1] == '#')
				count_d++;
			if (str[i - 5] == '#')
				count_d++;
		}
		i++;
	}
	return (count_d);
}

int			check_c(char *str, char c)
{
	int		i;
	int		len;

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

int			check_end_line(char *str)
{
	int		count;
	int		len;

	count = 0;
	len = 4;
	if (str == NULL)
		return (0);
	while (str[len] && len < 21)
	{
		if (str[len] == '\n')
			count++;
		len = len + 5;
	}
	return (count);
}

int			ft_check_grid(char **str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != NULL)
	{
		if (check_c(str[i], '.') == 12 && check_c(str[i], '#') == 4 &&
				(check_end_line(str[i]) == 4 || check_end_line(str[i]) == 3) &&
				(check_link(str[i]) == 6 || check_link(str[i]) == 8))
			i++;
		else
			return (0);
	}
	if (str[i] == NULL)
		return (1);
	return (0);
}
