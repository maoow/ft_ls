/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:56:34 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/04 17:42:27 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		countnbchar(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char		*ft_return_zero(void)
{
	char	*str;

	str = ft_strdup("0");
	if (str)
		return (str);
	return (NULL);
}

static char		*ft_return_min(void)
{
	char	*min;
	char	*str;

	if ((str = (char *)malloc((12) * sizeof(*str))) == NULL)
		return (NULL);
	min = "-2147483648";
	str = ft_strcpy(str, min);
	return (str);
}

char			*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		len;

	if (!nb)
		return (ft_return_zero());
	if (nb == -2147483648)
		return (ft_return_min());
	len = countnbchar(nb);
	if ((str = (char *)malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	str[len] = '\0';
	i = len;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
