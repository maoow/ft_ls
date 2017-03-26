/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 03:20:15 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strfirstprintable(char const *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '	' || s[i] == '\n'))
		i++;
	return (i);
}

static int	ft_getprintablesize(char const *s, int start)
{
	int i;
	int len;

	i = start;
	while (s[i])
		i++;
	i--;
	while (i && (s[i] == ' ' || s[i] == '	' || s[i] == '\n'))
		i--;
	len = i - start;
	if (len < 0)
		len = 0;
	if (len >= 0)
		len++;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		start;
	char	*str;

	if (!s)
		return (NULL);
	start = ft_strfirstprintable(s);
	len = ft_getprintablesize(s, start);
	if ((str = (char *)malloc((len) * sizeof(*str))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
