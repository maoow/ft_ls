/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:54:19 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 21:12:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_initstr(t_buf_f *buffer, char *str)
{
	int		i;

	i = 0;
	str[FLAGS.minimum] = '\0';
	while (i < FLAGS.minimum || i < FLAGS.precision)
	{
		if ((FLAGS.zero && (FLAGS.string || !FLAGS.isprecision ||
						FLAGS.precision + i >= FLAGS.minimum)) ||
				(FLAGS.isprecision && !FLAGS.string && i >= FLAGS.minimum
					- FLAGS.precision && !FLAGS.m) ||
				(FLAGS.isprecision && !FLAGS.string && i < FLAGS.minimum
					- FLAGS.precision && FLAGS.m && !FLAGS.p))
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	return (str);
}

void		ft_placeminus(char *str, char *dst, int i)
{
	int		j;

	j = 0;
	while (dst[j + 1] == ' ' && j < i)
		j++;
	dst[j] = '-';
	if (j < i)
		*str = '0';
}

char		*ft_placestr(t_buf_f *buffer, char *str, char *dst)
{
	int		i;
	int		size;

	size = ft_strlen(str);
	if (FLAGS.string && FLAGS.isprecision && FLAGS.precision < ft_strlen(str))
		size -= FLAGS.precision;
	if (!FLAGS.m && (!FLAGS.string && FLAGS.minimum < FLAGS.precision))
		FLAGS.minimum = FLAGS.precision;
	if (!FLAGS.m)
		i = FLAGS.minimum - size;
	else if (FLAGS.precision > ft_strlen(str) && FLAGS.minimum > ft_strlen(str))
		i = FLAGS.precision - ft_strlen(str);
	else
		i = 0;
	if (*str == '-' && !FLAGS.string && (FLAGS.zero || (FLAGS.isprecision &&
					FLAGS.minimum)))
		ft_placeminus(str, dst, i);
	while (*str && i < FLAGS.minimum)
	{
		dst[i] = *str;
		i++;
		str++;
	}
	return (dst);
}

char		*ft_plusit(t_buf_f *buffer, char *str)
{
	char *dst;

	if ((str[0] == '0' || str[0] == ' ') && str[1] &&
			(!FLAGS.m && (ft_strdlen(str) <= FLAGS.precision ||
					!FLAGS.isprecision)))
	{
		dst = str;
		while (*(str + 1) == ' ' || *(str + 1) == '-' || *(str + 1) == '+')
			str++;
		if (*str != '-')
			*str = '+';
	}
	else
	{
		if (ft_strchr(str, '+'))
			return (str);
		dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(*dst));
		dst[0] = '+';
		ft_strcpy(dst + 1, str);
		if (dst[1] == ' ')
			dst[1] = '0';
		free(str);
	}
	return (dst);
}
