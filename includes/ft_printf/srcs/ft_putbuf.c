/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:01 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 23:24:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putbuf(t_buf_f *buffer)
{
	write(1, buffer->buf, buffer->cursor);
	buffer->total += buffer->cursor;
	buffer->cursor = 0;
}
