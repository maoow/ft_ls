/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:51:35 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/07 11:34:30 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getbool(t_buf_f *buffer, va_list ap, char *format)
{
	int	b_arg;

	b_arg = va_arg(ap, int);
	if (b_arg)
		ft_buffit(buffer, "\033[32mTRUE\033[0m", 13);
	else
		ft_buffit(buffer, "\033[31mFALSE\033[0m", 14);
	return (format);
}

char	*ft_getpermissions(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int	nb;
	char			*per;
	char			str[9];
	int				i;

	i = 8;
	per = ft_strdup("rwx");
	nb = va_arg(ap, unsigned int);
	while (i >= 0)
	{
		if (nb % 2 == 1)
			str[i] = per[i % 3];
		else
			str[i] = '-';
		nb /= 2;
		i--;
	}
	ft_buffit(buffer, str, 9);
	free(per);
	return (format);
}

char	*ft_getbits(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned char	nb;
	char			str[8];
	int				i;

	i = 7;
	if (FLAGS.sharp)
		return (ft_getpermissions(buffer, ap, format));
	nb = (unsigned char)va_arg(ap, unsigned int);
	while (i >= 0)
	{
		if (nb % 2 == 1)
			str[i] = '1';
		else
			str[i] = '0';
		nb /= 2;
		i--;
	}
	ft_buffit(buffer, str, 8);
	return (format);
}
