/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/05 12:44:18 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "verif_grid.c"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 600

char	*ft_split_tetri(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = '@';
		i = i + 20;
	}
	return (str);
}

int		read_file(char *str)
{
	int fd;
	int ret;
	char **s;
	int i;
	char buf[BUF_SIZE + 1];

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open () error");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	ft_split_tetri(buf);
	s = ft_strsplit(buf, '@');
	if (ft_check_grid(s) == 1)
		printf("VALID_GRILL");
	else
		printf("PAS ASSEZ DE POINTS");
	if (close(fd) == -1)
	{
		ft_putstr("Close() error");
		return (0);
	}	
	return (1);
}

int main(int ac, char *av[])
{
	char **str;
	int i;

	i = 0;
	str = NULL;
	if (ac != 2)
		ft_putstr("Fais attention Grooos");
	else
	{
		read_file(av[1]);
	}
	return (0);
}
