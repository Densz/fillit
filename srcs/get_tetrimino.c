/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:32:39 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/13 12:10:08 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int					ft_check(char **tab, t_position tetriminos, int max)
{
	int				x;
	int				y;
	int				i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetriminos.x[i] == x && tetriminos.y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tetriminos.x[i] == x && tetriminos.y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

t_position			ft_update_pos(t_position tetriminos, int x, int y)
{
	int				xmin;
	int				ymin;
	int				i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i < 4)
	{
		if (tetriminos.x[i] < xmin)
			xmin = tetriminos.x[i];
		if (tetriminos.y[i] < ymin)
			ymin = tetriminos.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetriminos.x[i] = tetriminos.x[i] - xmin + x;
		tetriminos.y[i] = tetriminos.y[i] - ymin + y;
		i++;
	}
	return (tetriminos);
}

t_position			*ft_get_tetriminos(char **str)
{
	t_position		*ptr;
	int				i;
	int				j;
	char			letter;
	int				x;
	int				y;

	j = 0;
	letter = 'A';
	ptr = (t_position *)malloc(sizeof(t_position) * (ft_count_tetri(str) + 1));
	while (str[j])
	{
		i = 0;
		x = 0;
		y = 0;
		ptr[j].abc = letter;
		while (str[j][i])
		{
			if (ft_isalpha(str[j][i]))
			{
				ptr[j].x[x++] = i % 5;
				ptr[j].y[y++] = i / 5;
			}
			i++;
		}
		j++;
		letter++;
	}
	return (ptr);
}
