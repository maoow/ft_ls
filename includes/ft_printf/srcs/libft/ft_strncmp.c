/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:03:23 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i == 0 && (*s1 || *s2) && j < size)
	{
		i = *(unsigned char *)s1 - *(unsigned char *)s2;
		s1++;
		s2++;
		j++;
	}
	return (i);
}
