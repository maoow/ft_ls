/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:22:01 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/11 16:12:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putstr("-2");
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putlunbr(unsigned long int n)
{
	if (n >= 10)
		ft_putlunbr(n / 10);
	ft_putchar(n % 10 + '0');
}
