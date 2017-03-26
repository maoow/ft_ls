/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbrbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:31:04 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/10 17:09:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbrbase(unsigned long int nb, char *base)
{
	unsigned long int nbase;

	nbase = ft_strlen(base);
	if (nb >= nbase)
		ft_putlnbrbase(nb / nbase, base);
	ft_putchar(base[nb % nbase]);
}

void	ft_putloctal(unsigned long int nb)
{
	ft_putlnbrbase(nb, "012345678");
}

void	ft_putlhexa(unsigned int nb)
{
	ft_putnbrbase(nb, "0123456789ABCDEF");
}
