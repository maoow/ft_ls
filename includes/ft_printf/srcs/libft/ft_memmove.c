/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:53:55 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/12 21:15:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rmemcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*str;

	str = dst;
	i = n;
	str = &str[n];
	src = &src[n];
	while (i > 0)
	{
		i--;
		src--;
		str--;
		*(char *)str = *(char *)src;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		ft_rmemcpy(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
