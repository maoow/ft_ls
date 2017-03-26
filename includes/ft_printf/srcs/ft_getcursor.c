/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:09:16 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 23:24:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getcursor(t_buf_f *buffer, va_list ap, char *format)
{
	int		*i;

	i = va_arg(ap, int *);
	*i = (int)(buffer->cursor + buffer->total);
	return (format);
}
