/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/13 12:55:16 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void				ft_printstrs(char **str)
{
	int				i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int					ft_max_size(int nbr_tetri)
{
	int				max;

	max = 2;
	while (max * max < nbr_tetri * 4)
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
	t_position		*tetriminos;
	char			**resolution;
	int				i;
	int				nbr_tetri;

	i = 0;
	nbr_tetri = 2;
	if (ac != 2)
		ft_putstr("Error ()");
	else
	{
		str = read_file(av[1]);
		ft_printstrs(str);
		if (ft_check_grid(str) == 1)
		{
			str = ft_put_letters(str);
			ft_printstrs(str);
			nbr_tetri = ft_count_tetri(str);
			printf("Number of tetriminos : %i\n\n", nbr_tetri);
			tetriminos = ft_get_tetriminos(str);
			while (i < nbr_tetri)
			{
				printf("Tetriminos %c\n", tetriminos[i].abc);
				printf("x : %i\t%i\t%i\t%i\n", tetriminos[i].x[0], tetriminos[i].x[1], tetriminos[i].x[2], tetriminos[i].x[3]);
				printf("y : %i\t%i\t%i\t%i\n\n", tetriminos[i].y[0], tetriminos[i].y[1], tetriminos[i].y[2], tetriminos[i].y[3]);
				i++;
			}
			resolution = ft_solve(tetriminos, ft_max_size(nbr_tetri), nbr_tetri);
			ft_printstrs(resolution);
		}
		else
			printf("UNVALID GRILL - TRY AGAIN");
	}
	return (0);
}
