/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:17:28 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/04 17:42:27 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*ft_return_zero(void)
{
	char	*str;

	str = ft_strdup("0");
	if (str)
		return (str);
	return (NULL);
}

static int		mcountnbchar(intmax_t nb)
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

static char		*ft_return_lmin(void)
{
	char	*min;
	char	*str;

	if ((str = (char *)malloc((21) * sizeof(*str))) == NULL)
		return (NULL);
	min = "-9223372036854775808";
	str = ft_strcpy(str, min);
	return (str);
}

char			*ft_mitoa(intmax_t nb)
{
	char	*str;
	int		i;
	int		len;

	if (!nb)
		return (ft_return_zero());
	if (nb == LONG_MIN)
		return (ft_return_lmin());
	len = mcountnbchar(nb);
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
