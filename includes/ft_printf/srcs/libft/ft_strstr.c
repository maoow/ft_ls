/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:50:37 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		i = 0;
		while (*big != *little && *big)
			big++;
		while (big[i] == little[i] && little[i] && big[i])
			i++;
		if (little[i] == '\0')
			return ((char *)big);
		if (*big)
			big++;
	}
	return (NULL);
}
