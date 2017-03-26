/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:59:45 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/07 14:18:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"

void	ft_initbufferf(t_buf_f *buffer)
{
	buffer->flags.sharp = false;
	buffer->flags.zero = false;
	buffer->flags.space = false;
	buffer->flags.m = false;
	buffer->flags.p = false;
	buffer->flags.pp = false;
	buffer->flags.hh = false;
	buffer->flags.h = false;
	buffer->flags.l = false;
	buffer->flags.ll = false;
	buffer->flags.j = false;
	buffer->flags.z = false;
	buffer->flags.minimum = 0;
	buffer->flags.isprecision = false;
	buffer->flags.precision = 0;
	buffer->flags.string = false;
	buffer->flags.signe = false;
	buffer->flags.uppercase = false;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buf_f		buffer;

	buffer.cursor = 0;
	buffer.total = 0;
	ft_initbufferf(&buffer);
	va_start(ap, format);
	ft_getf(&buffer, ap, (char *)format);
	va_end(ap);
	return (buffer.total);
}
