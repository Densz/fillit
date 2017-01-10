/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:44:07 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/16 18:28:02 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char				**ft_empty_grid(char **tab, int max)
{
	int				x;
	int				y;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = (char *)malloc(sizeof(char) * (max + 1));
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char				**ft_reset_tab(char **tab, t_pos tris)
{
	int				x;
	int				y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == tris.abc)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char				**ft_write(char **tab, t_pos tris)
{
	int				x;
	int				y;
	int				i;

	i = 0;
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tris.x[i] == x && tris.y[i] == y)
			{
				tab[y][x] = tris.abc;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tab);
}

char				**ft_fill(char **tab, t_pos *tris, int cnt, int i)
{
	int				x;
	int				y;
	char			**tmp;

	y = 0;
	if (i == cnt)
		return (tab);
	tmp = NULL;
	while (tab[y] && i < cnt)
	{
		x = 0;
		while (tab[y][x] && i < cnt)
		{
			tris[i] = ft_update_pos(tris[i], x, y);
			if (ft_check(tab, tris[i]) == 1)
				tmp = ft_fill(ft_write(tab, tris[i]), tris, cnt, (i + 1));
			if (tmp != NULL)
				return (tmp);
			tab = ft_reset_tab(tab, tris[i]);
			x++;
		}
		y++;
	}
	return (NULL);
}

char				**ft_solve(t_pos *tris, int max, int cnt)
{
	char			**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_empty_grid(tab, max);
		tab = ft_fill(tab, tris, cnt, 0);
		max++;
	}
	return (tab);
}
