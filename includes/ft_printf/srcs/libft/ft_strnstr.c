/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:16:33 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:55 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	j = 0;
	while (big[j] && j < n)
	{
		i = 0;
		while (big[j] != *little && big[j] && j < n)
			j++;
		while (big[i + j] == little[i] && little[i]
				&& big[i + j] && (j + i) < n)
			i++;
		if (little[i] == '\0')
			return ((char *)&big[j]);
		if (big[j])
			j++;
	}
	return (NULL);
}
