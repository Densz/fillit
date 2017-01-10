/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:35:52 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/27 10:29:46 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <string.h>

# define BUF_SIZE 600

typedef struct				s_position
{
	char					abc;
	int						x[4];
	int						y[4];
}							t_pos;

int							check_c(char *str, char c);
int							ft_check_grid(char **str);
char						**ft_put_letters(char **str);
char						*ft_split_tetri(char *str);
char						**read_file(char *str);
t_pos						*ft_get_tetriminos(char **str, int nbr_tetri);
void						solver(void);
char						**ft_grid_solver(t_pos *tetriminos,
							char **empty_grid, int size);
char						**ft_empty_grid(char **tab, int size);
char						**ft_solve(t_pos *tetriminos,
							int max, int nbr_tetri);
void						ft_printstrs(char **str);
int							ft_count_tetri(char **str);
int							ft_check(char **tab, t_pos tetriminos);
t_pos						ft_update_pos(t_pos tetriminos, int x, int y);

#endif
