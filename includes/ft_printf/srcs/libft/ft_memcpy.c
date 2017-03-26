/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:36:27 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/16 12:57:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*str;

	str = dst;
	i = 0;
	while (i < n)
	{
		*(char *)str = *(char *)src;
		str++;
		src++;
		i++;
	}
	return (dst);
}
