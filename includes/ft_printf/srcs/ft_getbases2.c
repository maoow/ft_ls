/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbases2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:16:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 20:45:33 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_nuloctal(t_buf_f *buffer, char *format)
{
	char	flag;

	flag = ' ';
	while (FLAGS.minimum-- && !FLAGS.m)
		ft_buffit(buffer, &flag, 1);
	if (FLAGS.sharp)
		ft_buffit(buffer, "0", 1);
	while (FLAGS.minimum-- && FLAGS.m)
		ft_buffit(buffer, &flag, 1);
	return (format);
}

char		*ft_nulnbr(t_buf_f *buffer, char *format)
{
	char	flag;

	flag = ' ';
	while (FLAGS.minimum-- && !FLAGS.m)
		ft_buffit(buffer, &flag, 1);
	return (format);
}

char		*ft_getoctal(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char				*str;

	if (!FLAGS.l && !FLAGS.ll && !FLAGS.j && !FLAGS.z)
	{
		if (FLAGS.hh)
			nb = (unsigned char)va_arg(ap, unsigned int);
		else if (FLAGS.h)
			nb = (unsigned short)va_arg(ap, unsigned int);
		else
			nb = va_arg(ap, unsigned int);
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (ft_nuloctal(buffer, format));
		str = ft_itoabase(nb, "01234567");
		if (FLAGS.sharp && nb > 0)
			str = ft_strjoin("0", str);
		FLAGS.sharp = false;
		if (FLAGS.precision || FLAGS.minimum)
			str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getloctal(buffer, ap, format);
	return (format);
}
