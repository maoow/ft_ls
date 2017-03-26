/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:40:35 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 20:41:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getnbr(t_buf_f *buffer, va_list ap, char *format)
{
	int		nb;
	char	*str;

	FLAGS.signe = true;
	if (!FLAGS.l && !FLAGS.ll && !FLAGS.j && !FLAGS.z && !FLAGS.h)
	{
		if (!FLAGS.hh)
			nb = va_arg(ap, int);
		else
			nb = (char)va_arg(ap, int);
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (ft_nulnbr(buffer, format));
		if (nb > 0 && FLAGS.p && FLAGS.minimum && FLAGS.m)
			FLAGS.minimum--;
		if (nb < 0)
			FLAGS.space = false;
		if (nb < 0 && FLAGS.precision > FLAGS.minimum)
			FLAGS.precision++;
		str = ft_flagit(buffer, ft_itoa(nb));
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getlnbr(buffer, ap, format);
	return (format);
}

char	*ft_getmnbr(t_buf_f *buffer, va_list ap, char *format)
{
	intmax_t	nb;
	char		*str;

	FLAGS.signe = true;
	nb = va_arg(ap, intmax_t);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
		return (format);
	str = ft_mitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getumnbr(t_buf_f *buffer, va_list ap, char *format)
{
	uintmax_t	nb;
	char		*str;

	nb = va_arg(ap, uintmax_t);
	if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
		return (format);
	str = ft_umitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getlnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long int		nb;
	char			*str;

	if (!FLAGS.ll && !FLAGS.j && !FLAGS.z)
	{
		if (!FLAGS.h || !FLAGS.signe)
			nb = va_arg(ap, long int);
		else
			nb = (short)va_arg(ap, long int);
		FLAGS.signe = true;
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (format);
		str = ft_litoa(nb);
		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getllnbr(buffer, ap, format);
	return (format);
}

char	*ft_getllnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long long int		nb;
	char				*str;

	if (!FLAGS.j &&
			!FLAGS.z)
	{
		FLAGS.signe = true;
		nb = va_arg(ap, long long int);
		if (nb == 0 && FLAGS.precision == 0 && FLAGS.isprecision)
			return (format);
		str = ft_llitoa(nb);
		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getmnbr(buffer, ap, format);
	return (format);
}
