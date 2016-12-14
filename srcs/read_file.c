/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:58:15 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/14 10:32:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

#define BUF_SIZE 550

char			*ft_split_tetri(char *str)
{
	size_t		i;
	size_t		len;

	i = 20;
	len = ft_strlen(str);
	while (str[i] && i < len - 2)
	{
		if (str[i] == '\n')
			str[i] = '@';
		i = i + 21;
	}
	return (str);
}

char			**read_file(char *str)
{
	int			fd;
	int			ret;
	char		**s;
	int			i;
	char		buf[BUF_SIZE + 1];

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
