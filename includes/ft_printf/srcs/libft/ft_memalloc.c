/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 04:18:08 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 12:59:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*tab;
	void	*mem;
	size_t	i;

	i = 0;
	if ((tab = (int *)malloc(size * sizeof(*tab))) == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	mem = tab;
	return (mem);
}
