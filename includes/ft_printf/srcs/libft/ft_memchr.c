/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:57:10 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:01:12 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	if (n == 0)
		return (NULL);
	i = 1;
	while (i < n && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		i++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return ((void*)s);
	return (NULL);
}
