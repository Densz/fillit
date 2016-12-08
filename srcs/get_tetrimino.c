/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:32:39 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/07 17:44:16 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_position	*ft_get_tetriminos(char **str)
{
	t_position 	*tetrimino;
	t_position	*ptr;
	int 			i;
	int 			j;
	char 			letter;
	int				x;
	int 			y;

	j = 0;
	letter = 'A';
	if (!(tetrimino = (t_position *)malloc(sizeof(t_position))))
		return (NULL);
	ptr = tetrimino;
	while (str[j] != NULL)
	{
		i = 0;
		x = 0;
		y = 0;
		ptr->tetrimino = ft_strdup(str[j]);
		ptr->abc = letter;
		while (str[j][i] != '\0')
		{
			if (ft_isalpha(str[j][i]))
			{
				ptr->x[x++] = i % 5;
				ptr->y[y++] = i / 5;
			}
			i++;
		}
		if (!(ptr->next = (t_position *)malloc(sizeof(t_position))))
			return (NULL);
		ptr = ptr->next;
		j++;
		letter++;
	}
	ptr->next = NULL;
	return (tetrimino);
}