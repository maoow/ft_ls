/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:10:00 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	buf[size];
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
	{
		buf[i] = dst[i];
		i++;
	}
	if (i == size)
		return (i + ft_strlen((char *)src));
	j = 0;
	while (src[j] && i + j < size - 1)
	{
		buf[i + j] = src[j];
		j++;
	}
	buf[i + j] = '\0';
	j = 0;
	ft_strcpy(dst, buf);
	return (i + ft_strlen((char*)src));
}
