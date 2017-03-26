/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:17:20 by cbinet            #+#    #+#             */
/*   Updated: 2017/02/28 14:15:44 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buffit(t_buf_f *buffer, char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		while (i < size && buffer->cursor < BUFF_SIZE)
		{
			if (str[i])
				buffer->buf[buffer->cursor] = str[i];
			i++;
			buffer->cursor++;
		}
		if (i < size)
			ft_putbuf(buffer);
	}
}

void	ft_intbuffit(t_buf_f *buffer, unsigned int *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		while (i < size && buffer->cursor < BUFF_SIZE)
		{
			if (str[i])
				buffer->buf[buffer->cursor] = str[i];
			else
			{
				buffer->buf[buffer->cursor] = '\0';
			}
			i++;
			buffer->cursor++;
		}
		if (i < size)
			ft_putbuf(buffer);
	}
}
