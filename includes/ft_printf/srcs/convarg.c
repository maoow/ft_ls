/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:15:28 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/15 16:35:58 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			g_tab[21] = {
	's',
	'S',
	'p',
	'P',
	'd',
	'D',
	'i',
	'o',
	'O',
	'u',
	'U',
	'x',
	'X',
	'c',
	'C',
	'{',
	'%',
	'n',
	'B',
	'b',
	'k'
};

char			g_fltab[10] = {
	'#',
	'0',
	'-',
	'+',
	' ',
	'h',
	'l',
	'j',
	'z',
	'.'
};
void			*g_ftab[21] = {
	&ft_getstr,
	&ft_getsstr,
	&ft_getptr,
	&ft_getstrptr,
	&ft_getnbr,
	&ft_getlnbr,
	&ft_getnbr,
	&ft_getoctal,
	&ft_getloctal,
	&ft_getunbr,
	&ft_getlunbr,
	&ft_gethexa,
	&ft_getlhexa,
	&ft_getchar,
	&ft_getwchar,
	&ft_getcolor,
	&ft_getpercent,
	&ft_getcursor,
	&ft_getbool,
	&ft_getbits,
	&ft_gettime
};

bool			ft_isconv(char c)
{
	int		i;

	i = 0;
	while (i < 21)
	{
		if (g_tab[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool			ft_isflag(char c)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (g_fltab[i] == c)
			return (true);
		i++;
	}
	return (false);
}

void			*getconv(char c)
{
	int		i;

	i = 0;
	while (i < 21)
	{
		if (g_tab[i] == c)
			return (g_ftab[i]);
		i++;
	}
	return (NULL);
}

static char		*ft_invalidconv(t_buf_f *buffer, char *format, int i)
{
	if (FLAGS.m && format[i])
		ft_buffit(buffer, format + i, 1);
	if (FLAGS.minimum)
	{
		FLAGS.minimum--;
		while (FLAGS.minimum)
		{
			if (!FLAGS.zero)
				ft_buffit(buffer, " ", 1);
			else
				ft_buffit(buffer, "0", 1);
			FLAGS.minimum--;
		}
	}
	if (!FLAGS.m && format[i])
		ft_buffit(buffer, format + i, 1);
	if (format[i])
		i++;
	return (format + i);
}

char			*convarg(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	char	*(*conv)();

	i = 0;
	ft_initbufferf(buffer);
	while (!ft_isconv(format[i]))
	{
		ft_setflags(buffer, &format[i]);
		if (format[i] > '0' && format[i] <= '9')
		{
			if (format[i - 1] != '.')
				FLAGS.minimum = (size_t)ft_atoi(format + i);
			while (format[i + 1] >= '0' && format[i + 1] <= '9')
				i++;
		}
		if (!format[i] || (!ft_isconv(format[i]) && !ft_isflag(format[i]) &&
					!ft_isdigit(format[i])))
			return (ft_invalidconv(buffer, format, i));
		i++;
	}
	if (FLAGS.precision > FLAGS.minimum)
		FLAGS.m = false;
	conv = getconv(format[i]);
	format = conv(buffer, ap, format + i);
	return (format + 1);
}
