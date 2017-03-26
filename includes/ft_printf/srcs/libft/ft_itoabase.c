/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:06:08 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/04 18:47:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countnbchar(unsigned int nb, int nbase)
{
	int i;

	i = 0;
	while (nb)
	{
		nb /= nbase;
		i++;
	}
	return (i);
}

static char		*ft_return_zero(void)
{
	char	*min;
	char	*str;

	if ((str = (char *)malloc((2) * sizeof(*str))) == NULL)
		return (NULL);
	min = "0";
	str = ft_strcpy(str, min);
	return (str);
}

char			*ft_itoabase(unsigned int nb, char *base)
{
	char	*str;
	int		i;
	int		len;
	int		nbase;

	nbase = ft_strlen(base);
	if (!nb)
		return (ft_return_zero());
	len = countnbchar(nb, nbase);
	if ((str = (char *)malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	str[len] = '\0';
	i = len;
	while (nb)
	{
		i--;
		str[i] = base[nb % nbase];
		nb /= nbase;
	}
	return (str);
}
