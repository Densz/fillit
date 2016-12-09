/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/07 11:25:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int main(int ac, char *av[])
{
	char 			**str;
	int 			i;
	t_position 	*tetriminos;
	t_position 	*next;

	i = 65;
	if (ac != 2)
		ft_putstr("Error ()");
	else
	{
		str = read_file(av[1]);
		if (ft_check_grid(str) == 1)
		{
			str = ft_put_letters(str);
			tetriminos = ft_get_tetriminos(str);
			while (tetriminos != NULL)
			{
				next = tetriminos->next;
				printf("Position x : %i\t", tetriminos->x[0]);
				ft_putstr("\n");
				printf("Position y : %i\n", tetriminos->y[0]);
				printf("Tetriminos %c\n%s\n", tetriminos->abc, tetriminos->tetrimino);
				tetriminos = next;
			}
		}
		else
			printf("UNVALID GRILL - TRY AGAIN");
	}
	return (0);
}
