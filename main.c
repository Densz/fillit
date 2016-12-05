/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/02 18:49:09 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 600

char	*check_tetriminos(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = 'Z';
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
	check_tetriminos(buf);
	s = ft_strsplit(buf, 'Z');
	while (s[i] != NULL)
	{
		printf("Tetriminos %d\n%s\n", i, s[i]);
		i++;
	}
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
