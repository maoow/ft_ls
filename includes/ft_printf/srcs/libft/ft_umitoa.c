/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:16:27 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/04 17:42:27 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char				*ft_return_zero(void)
{
	char	*str;

	str = ft_strdup("0");
	if (str)
		return (str);
	return (NULL);
}

static unsigned int		umcountnbchar(uintmax_t nb)
{
	unsigned int i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char					*ft_umitoa(uintmax_t nb)
{
	char			*str;
	int				i;
	unsigned int	len;

	if (!nb)
		return (ft_return_zero());
	len = umcountnbchar(nb);
	if ((str = (char *)malloc((len + 1) * sizeof(*str))) == NULL)
		return (NULL);
	str[len] = '\0';
	i = len;
	while (nb)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
