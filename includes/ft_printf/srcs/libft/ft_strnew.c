/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 05:46:31 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:55 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	size++;
	if ((str = (char *)malloc(size * sizeof(*str))) == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
