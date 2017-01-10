/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:58:15 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/22 10:58:28 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

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

int				check_len(char *str)
{
	int len;

	len = ft_strlen(str);
	len = len + 1;
	if (len % 21 != 0 || len > 546)
		return (1);
	else
		return (0);
}

char			**read_file(char *str)
{
	int			fd;
	int			ret;
	char		**s;
	int			i;
	char		buf[BUF_SIZE + 1];

	s = NULL;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open () error");
	}
	ret = read(fd, buf, BUF_SIZE);
	if (check_len(buf) == 1)
		return (NULL);
	ft_split_tetri(buf);
	s = ft_strsplit(buf, '@');
	if (close(fd) == -1)
	{
		ft_putstr("Close() error");
	}
	return (s);
}
