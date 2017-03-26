/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:49:31 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/16 12:58:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (*(unsigned char *)src != (unsigned char)c && i < n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		src++;
		dst++;
		i++;
	}
	if (i < n && *(unsigned char *)src == (unsigned char)c)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		return (dst);
	}
	return (NULL);
}
