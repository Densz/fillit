/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:32:39 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/27 15:16:42 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int				ft_check(char **tab, t_pos tris)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[x])
		{
			if (tris.x[i] == x && tris.y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tris.x[i] == x && tris.y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

t_pos			ft_update_pos(t_pos tris, int x, int y)
{
	int			xmin;
	int			ymin;
	int			i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i < 4)
	{
		if (tris.x[i] < xmin)
			xmin = tris.x[i];
		if (tris.y[i] < ymin)
			ymin = tris.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tris.x[i] = tris.x[i] - xmin + x;
		tris.y[i] = tris.y[i] - ymin + y;
		i++;
	}
	return (tris);
}

t_pos			*ft_get_tetriminos(char **str, int nbr_tetri)
{
	t_pos		*ptr;
	int			i;
	int			j;
	int			x;
	int			y;

	j = -1;
	ptr = (t_pos *)malloc(sizeof(t_pos) * (nbr_tetri + 1));
	while (str[++j])
	{
		i = -1;
		x = 0;
		y = 0;
		ptr[j].abc = 66 + i + j;
		while (str[j][++i])
		{
			if (ft_isalpha(str[j][i]))
			{
				ptr[j].x[x++] = i % 5;
				ptr[j].y[y++] = i / 5;
			}
		}
	}
	return (ptr);
}
