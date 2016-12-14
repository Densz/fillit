/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:35:52 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/13 11:28:41 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <string.h>

//ATTENTION A SUPPRIMER
# include <stdio.h>

typedef struct				s_position
{
	char					abc;
	int						x[4];
	int						y[4];
}							t_position;

int                 check_c(char *str, char c);
int                 ft_check_grid(char **str);
char                **ft_put_letters(char **str);
char				*ft_split_tetri(char *str);
char				**read_file(char *str);
t_position			*ft_get_tetriminos(char **str);
void				solver(void);
char				**ft_grid_solver(t_position *tetriminos, char **empty_grid, int size);
char				**ft_empty_grid(char **tab, int size);
char				**ft_solve(t_position *tetriminos, int max, int nbr_tetri);
void 				ft_printstrs(char **str);
int					ft_count_tetri(char **str);
int					ft_check(char **tab, t_position tetriminos, int max);
t_position			ft_update_pos(t_position tetriminos, int x, int y);

#endif
