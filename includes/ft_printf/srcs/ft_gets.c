/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:41:53 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 21:12:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_getunbr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char				*str;

	if (!FLAGS.l && !FLAGS.ll && !FLAGS.j && !FLAGS.z)
	{
		if (!FLAGS.hh)
			nb = va_arg(ap, unsigned int);
		else
			nb = (unsigned char)va_arg(ap, unsigned int);
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (format);
		str = ft_uitoa(nb);
		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else if (!FLAGS.j)
		ft_getlunbr(buffer, ap, format);
	else
		ft_getumnbr(buffer, ap, format);
	return (format);
}

char		*ft_getlunbr(t_buf_f *buffer, va_list ap, char *format)
{
	long unsigned int		nb;
	char					*str;

	nb = va_arg(ap, long unsigned int);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
		return (format);
	str = ft_ulitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char		*ft_getchar(t_buf_f *buffer, va_list ap, char *format)
{
	char	c;
	char	flag;

	if (!FLAGS.zero)
		flag = ' ';
	else
		flag = '0';
	if (FLAGS.minimum > 0 && !FLAGS.m)
		while (FLAGS.minimum-- > 1)
			ft_buffit(buffer, &flag, 1);
	if (!FLAGS.l)
	{
		c = (char)va_arg(ap, int);
		ft_buffit(buffer, &c, 1);
	}
	else
		ft_getwchar(buffer, ap, format);
	if (FLAGS.minimum > 0 && FLAGS.m)
		while (FLAGS.minimum-- > 1)
			ft_buffit(buffer, &flag, 1);
	return (format);
}

static char	*ft_placepercent(t_buf_f *buffer)
{
	char		*str;
	int			i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (FLAGS.minimum));
	while (i < FLAGS.minimum)
	{
		str[i] = '0';
		if (!FLAGS.zero || FLAGS.m)
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	if (FLAGS.m)
		str[0] = '%';
	else
		str[FLAGS.minimum - 1] = '%';
	return (str);
}

char		*ft_getpercent(t_buf_f *buffer, va_list ap, char *format)
{
	char		*str;

	if (FLAGS.minimum)
		str = ft_placepercent(buffer);
	else
		str = ft_strdup("%");
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	if (ap)
		str = NULL;
	return (format);
}
