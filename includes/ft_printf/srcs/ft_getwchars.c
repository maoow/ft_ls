/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:43:47 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 20:32:41 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getwchar(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		c;

	c = va_arg(ap, unsigned int);
	if (c && c != 0)
		ft_bufwchar(buffer, c);
	else
		ft_intbuffit(buffer, &c, 1);
	return (format);
}

int		ft_bufwchar(t_buf_f *buffer, int c)
{
	int nb;
	int	i;

	i = 0;
	nb = c;
	if (c <= 128 && (FLAGS.precision > 0 || !FLAGS.isprecision))
	{
		ft_buffit(buffer, (char *)&c, 1);
		FLAGS.precision--;
	}
	else if (c <= 2048)
		ft_bufwchartwo(buffer, c);
	else if (c <= 65536)
		ft_bufwcharthree(buffer, c);
	else
		ft_bufwcharfour(buffer, c);
	while (nb)
	{
		i++;
		nb /= 64;
	}
	return (i);
}

void	ft_bufwchartwo(t_buf_f *buffer, int c)
{
	unsigned int					tab[2];

	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 192;
	if (FLAGS.precision > 1 || !FLAGS.isprecision)
	{
		ft_intbuffit(buffer, tab, 1);
		ft_intbuffit(buffer, tab + 1, 1);
	}
	FLAGS.precision -= 2;
}

void	ft_bufwcharthree(t_buf_f *buffer, int c)
{
	unsigned int					tab[3];

	tab[2] = c % 64 + 128;
	c /= 64;
	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 224;
	if (FLAGS.precision > 2 || !FLAGS.isprecision)
	{
		ft_intbuffit(buffer, tab, 1);
		ft_intbuffit(buffer, tab + 1, 1);
		ft_intbuffit(buffer, tab + 2, 1);
	}
	FLAGS.precision -= 3;
}

void	ft_bufwcharfour(t_buf_f *buffer, int c)
{
	unsigned int					tab[4];

	tab[3] = c % 64 + 128;
	c /= 64;
	tab[2] = c % 64 + 128;
	c /= 64;
	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 240;
	if (FLAGS.precision > 3 || !FLAGS.isprecision)
	{
		ft_intbuffit(buffer, tab, 1);
		ft_intbuffit(buffer, tab + 1, 1);
		ft_intbuffit(buffer, tab + 2, 1);
		ft_intbuffit(buffer, tab + 3, 1);
	}
	FLAGS.precision -= 4;
}
