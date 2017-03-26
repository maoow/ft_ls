/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:39:07 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 23:24:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getstr(t_buf_f *buffer, va_list ap, char *format)
{
	char	*str;

	if (!FLAGS.l)
	{
		str = ft_strdup(va_arg(ap, char *));
		if (!str)
			str = ft_strdup("(null)");
		FLAGS.string = true;
		if (FLAGS.precision > ft_strlen(str) || !FLAGS.isprecision)
			FLAGS.precision = ft_strlen(str);
		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_getsstr(buffer, ap, format);
	return (format);
}

void	ft_bufsstr(t_buf_f *buffer, int *str, char flag)
{
	int		i;
	int		size;

	i = 0;
	size = ft_wtablen(str);
	if (FLAGS.isprecision)
		size = ft_witablen(str, FLAGS.precision);
	while (i + size < FLAGS.minimum && !FLAGS.m)
	{
		i++;
		ft_buffit(buffer, &flag, 1);
	}
	while (*str)
	{
		ft_bufwchar(buffer, *str);
		str++;
	}
	while (i + size < FLAGS.minimum && FLAGS.m)
	{
		i++;
		ft_buffit(buffer, &flag, 1);
	}
}

char	*ft_getsstr(t_buf_f *buffer, va_list ap, char *format)
{
	int		*str;
	char	flag;

	if (!FLAGS.zero)
		flag = ' ';
	else
		flag = '0';
	str = va_arg(ap, wchar_t *);
	if (!str)
		ft_buffit(buffer, ft_strdup("(null)"), 6);
	else
		ft_bufsstr(buffer, str, flag);
	return (format);
}

char	*ft_getptr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char					*str;

	nb = va_arg(ap, unsigned long int);
	if (nb || FLAGS.precision || !FLAGS.isprecision)
	{
		if (FLAGS.zero)
		{
			FLAGS.string = true;
			FLAGS.m = true;
		}
		FLAGS.sharp = true;
		str = ft_litoabase(nb, "0123456789abcdef");
		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else
		ft_buffit(buffer, "0x", 2);
	return (format);
}
