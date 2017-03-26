/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:42:26 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/10 16:41:52 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase(unsigned int nb, char *base)
{
	unsigned int nbase;

	nbase = ft_strlen(base);
	if (nb >= nbase)
		ft_putnbrbase(nb / nbase, base);
	ft_putchar(base[nb % nbase]);
}

void	ft_putoctal(unsigned int nb)
{
	ft_putnbrbase(nb, "012345678");
}

void	ft_puthexa(unsigned int nb)
{
	ft_putnbrbase(nb, "0123456789abcdef");
}
