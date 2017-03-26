/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:41:43 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/15 16:35:58 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getloctal(t_buf_f *buffer, va_list ap, char *format)
{
	uintmax_t		nb;
	char			*str;

	nb = va_arg(ap, uintmax_t);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
	{
		if (FLAGS.sharp)
			ft_buffit(buffer, "0", 1);
		return (format);
	}
	str = ft_litoabase(nb, "01234567");
	if (FLAGS.sharp && nb > 0)
		str = ft_strjoin("0", str);
	FLAGS.sharp = false;
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_gethexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char				*str;

	if (!FLAGS.l && !FLAGS.ll && !FLAGS.j && !FLAGS.z)
	{
		if (FLAGS.hh)
			nb = (unsigned char)va_arg(ap, unsigned int);
		else
			nb = va_arg(ap, unsigned int);
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (ft_nulnbr(buffer, format));
		str = ft_itoabase(nb, "0123456789abcdef");
		if (!FLAGS.sharp || nb > 0)
			str = ft_flagit(buffer, str);
		if (!FLAGS.isprecision || FLAGS.precision > 0)
			ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getllhexa(buffer, ap, format);
	return (format);
}

char	*ft_getllhexa(t_buf_f *buffer, va_list ap, char *format)
{
	uintmax_t		nb;
	char			*str;

	if (FLAGS.hh)
		nb = (unsigned char)va_arg(ap, uintmax_t);
	else
		nb = va_arg(ap, uintmax_t);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
		return (format);
	str = ft_litoabase(nb, "0123456789abcdef");
	if (!FLAGS.sharp || nb > 0)
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getlhexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char					*str;

	if (FLAGS.hh)
		nb = (unsigned char)va_arg(ap, unsigned long int);
	else if (FLAGS.l || FLAGS.ll || FLAGS.z || FLAGS.j)
		nb = va_arg(ap, unsigned long int);
	else
		nb = (unsigned int)va_arg(ap, unsigned long int);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
		return (format);
	else
		str = ft_litoabase(nb, "0123456789ABCDEF");
	FLAGS.uppercase = true;
	if (!FLAGS.sharp || nb > 0)
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}
