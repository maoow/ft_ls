/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:20:10 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/11 16:23:36 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n && diff == 0)
	{
		diff = *(unsigned char *)s1 - *(unsigned char *)s2;
		i++;
		s1++;
		s2++;
	}
	return (diff);
}
