/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:07:45 by cbinet            #+#    #+#             */
/*   Updated: 2017/02/22 15:33:33 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_getf(t_buf_f *buffer, va_list ap, char *format)
{
	int	i;

	i = 0;
	while (*format)
	{
		while (format[i] != '%' && format[i] && format[i] != '{')
			i++;
		ft_buffit(buffer, format, i);
		format += i;
		i = 0;
		if (*format)
		{
			if (format[i] != '{')
				format++;
			format = convarg(buffer, ap, format);
		}
	}
	ft_putbuf(buffer);
}
