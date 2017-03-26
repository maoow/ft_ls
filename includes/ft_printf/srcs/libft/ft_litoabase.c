/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:05 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/27 19:57:02 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countnbchar(uintmax_t nb, int nbase)
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

char			*ft_litoabase(uintmax_t nb, char *base)
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
