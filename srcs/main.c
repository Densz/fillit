/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/22 11:47:51 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void				ft_printstrs(char **str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int					ft_max_size(int cnt)
{
	int				max;

	max = 2;
	while (max * max < cnt * 4)
		max++;
	return (max);
}

int					ft_count_tetri(char **str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int					main(int ac, char *av[])
{
	char			**str;
	t_pos			*tris;
	char			**resolution;
	int				cnt;

	str = NULL;
	resolution = NULL;
	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	else
	{
		cnt = 2;
		str = read_file(av[1]);
		if (ft_check_grid(str) == 1)
		{
			str = ft_put_letters(str);
			cnt = ft_count_tetri(str);
			tris = ft_get_tetriminos(str, cnt);
			resolution = ft_solve(tris, ft_max_size(cnt), cnt);
			ft_printstrs(resolution);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}
