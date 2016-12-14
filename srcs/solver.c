/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:44:07 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/13 14:24:53 by dzheng           ###   ########.fr       */
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

char				**ft_reset_tab(char **tab, t_position tetriminos, int max)
{
	int				x;
	int				y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == tetriminos.abc)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char				**ft_fill_tab(char **tab, t_position tetriminos, int max)
{
	int				x;
	int				y;
	int				i;

	i = 0;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetriminos.x[i] == x && tetriminos.y[i] == y)
			{
				tab[y][x] = tetriminos.abc;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tab);
}

char				**ft_fill_grid(char **tab, t_position *tetriminos, int max, int nbr_tetri, int i)
{
	int				x;
	int				y;
	char			**tmp_tab;

	y = 0;
	if (i == nbr_tetri)
		return (tab);
	tmp_tab = NULL;
	while (y < max && i < nbr_tetri)
	{
		x = 0;
		while (x < max && i < nbr_tetri)
		{
			tetriminos[i] = ft_update_pos(tetriminos[i], x, y);
			if (ft_check(tab, tetriminos[i], max) == 1)
				tmp_tab = ft_fill_grid(ft_fill_tab(tab, tetriminos[i], max), tetriminos, max, nbr_tetri, (i + 1));
			if (tmp_tab)
				return (tmp_tab);
			tab = ft_reset_tab(tab, tetriminos[i], max);
			x++;
		}
		y++;
	}
	return (NULL);
}

char				**ft_solve(t_position *tetriminos, int max, int nbr_tetri)
{
	char			**tab;
	int				i;

	i = 0;
	while (!tab)
	{
		tab = ft_empty_grid(tab, max);
		tab = ft_fill_grid(tab, tetriminos, max, nbr_tetri, i);
		max++;
	}
	return (tab);
}
