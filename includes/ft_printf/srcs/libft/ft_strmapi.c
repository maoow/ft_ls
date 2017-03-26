/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 02:05:49 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		if ((str = (char *)malloc((i + 1) * sizeof(*str))) == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
