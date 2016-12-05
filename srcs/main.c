/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:01:00 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/05 18:53:31 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 600

char	*ft_split_tetri(char *str)
{
	size_t i;

	i = 20;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = '@';
		i = i + 21;
	}
	return (str);
}

char  	**read_file(char *str)
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
	}
	ret = read(fd, buf, BUF_SIZE);
	ft_split_tetri(buf);
	s = ft_strsplit(buf, '@');
	if (close(fd) == -1)
	{
		ft_putstr("Close() error");
	}
	return (s);
}

int main(int ac, char *av[])
{
	char **str;
	int i;

	i = 0;
	if (ac != 2)
		ft_putstr("Fais attention Grooos");
	else
	{
		str = read_file(av[1]);
		if (ft_check_grid(str) == 1)
		{
			str = ft_put_letters(str);
			while (str[i])
			{
				printf("Tetrominos %d\n%s\n", i, str[i]);
				i++;
			}
		}
		else
			printf("UNVALID GRILL - TRY AGAIN");
	}
	return (0);
}
