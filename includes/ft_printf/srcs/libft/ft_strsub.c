/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 01:19:50 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillstrsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((str = (char *)malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (len == 0)
	{
		if ((str = (char *)malloc((1) * sizeof(*str))) == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i + start < len - 1)
	{
		if (!s[i + start])
			return (NULL);
		i++;
	}
	return (ft_fillstrsub(s, start, len));
}
