/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:50:52 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/18 15:17:01 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findfirstavail(char *str)
{
	int i;

	i = 0;
	while (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
	{
		if ((str[i] > 13 || str[i] < 9) && str[i] != ' ')
			return (0);
		i++;
	}
	return (i);
}

static bool	isavailable(char *str)
{
	int signe;
	int size;

	signe = 1;
	size = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (str[size] >= '0' && str[size] <= '9')
	{
		size++;
	}
	if (size == 19)
		if (ft_strncmp(str, "9223372036854775807", 19) > 0)
			return (false);
	if (size > 19)
		return (false);
	return (true);
}

int			ft_atoi(char *str)
{
	int nb;
	int signe;

	signe = 1;
	nb = 0;
	str = &str[ft_findfirstavail(str)];
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	if (!isavailable(str) && signe == 1)
		return (-1);
	if (!isavailable(str) && signe == -1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb * signe);
}
