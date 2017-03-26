/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:50:38 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/07 15:55:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strdlen(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
		if (str[i] != ' ' && str[i])
			j++;
	}
	return (j);
}

int	ft_sstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
