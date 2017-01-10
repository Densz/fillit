/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:19:40 by dzheng            #+#    #+#             */
/*   Updated: 2016/11/30 19:22:08 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	char	*src2;

	i = 0;
	src2 = (char *)src;
	while (src2[i])
	{
		dst[i] = src2[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
