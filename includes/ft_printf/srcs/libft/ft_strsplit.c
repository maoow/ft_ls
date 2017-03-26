/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:51:32 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char const *s, char c)
{
	int count;

	count = 0;
	while (*(char *)s)
	{
		while (*(char *)s && *(char *)s == c)
			s++;
		if (*(char *)s)
			count++;
		while (*(char *)s && *(char *)s != c)
			s++;
	}
	return (count);
}

static int		ft_splitlen(char const *s, char c)
{
	int i;

	i = 0;
	while (*(char *)s && *(char *)s == c)
		s++;
	while (*(char *)s && *(char *)s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char		*ft_fillword(char const *s, char **strtab, int j, char c)
{
	int i;
	int len;

	i = 0;
	while (*(char *)s && *(char *)s == c)
		s++;
	len = ft_splitlen(s, c);
	if (len == 0)
		return ("\0");
	if ((strtab[j] = (char *)malloc((len + 1) * sizeof(**strtab))) == NULL)
		return (NULL);
	while (*(char *)s && *(char *)s != c)
	{
		strtab[j][i] = *(char *)s;
		i++;
		s++;
	}
	strtab[j][i] = '\0';
	return ((char *)s);
}

static char		**ft_nulltab(char **strtab)
{
	if ((strtab = (char **)malloc(1 * sizeof(*strtab))) == NULL)
		return (NULL);
	strtab[0] = NULL;
	return (strtab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strtab;
	int		j;
	int		words;

	strtab = NULL;
	if (s == NULL)
		return (ft_nulltab(strtab));
	if (!*s || ft_splitlen(s, c) == 0 || countwords(s, c) == 0)
		return (ft_nulltab(strtab));
	words = countwords(s, c);
	strtab = (char **)malloc((countwords(s, c) + 1) * sizeof(*strtab));
	if (strtab == NULL)
		return (NULL);
	j = 0;
	while (j < words)
	{
		s = ft_fillword(s, strtab, j, c);
		j++;
	}
	strtab[words] = NULL;
	return (strtab);
}
