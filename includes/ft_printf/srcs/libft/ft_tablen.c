/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:20:21 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/04 17:43:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_witablen(int *tab, int precision)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	while (*tab)
	{
		nb = *tab;
		while (nb > 1)
		{
			nb /= 64;
			i++;
		}
		tab++;
		if (i <= precision)
			j = i;
	}
	return (j);
}

int		ft_wtablen(int *tab)
{
	int		i;
	int		nb;

	i = 0;
	while (*tab)
	{
		nb = *tab;
		while (nb)
		{
			nb /= 64;
			i++;
		}
		tab++;
	}
	return (i);
}
