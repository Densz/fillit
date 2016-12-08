/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:35:52 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/07 17:44:22 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <string.h>

typedef struct				s_position
{
	char					abc;//the first tetrimino name is A then B C ..
	char					*tetrimino;//tous les blocks
	int						x[4];
	int						y[4];
	struct s_position 	*next;
}							t_position;

int                 check_c(char *str, char c);
int                 ft_check_grid(char **str);
char                **ft_put_letters(char **str);
char				*ft_split_tetri(char *str);
char				**read_file(char *str);
t_position			*ft_get_tetriminos(char **str);

#endif
