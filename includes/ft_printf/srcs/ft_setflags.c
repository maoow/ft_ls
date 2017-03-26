/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:05:18 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 20:22:16 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_setprecision(t_buf_f *buffer, char *c)
{
	FLAGS.isprecision = true;
	FLAGS.precision = (size_t)ft_atoi(c + 1);
}

void			ft_setflags(t_buf_f *buffer, char *c)
{
	if (*c == '#')
		FLAGS.sharp = true;
	if (*c == '0' && !FLAGS.m)
		FLAGS.zero = true;
	if (*c == '-')
		FLAGS.m = true;
	if (*c == '+')
		FLAGS.p = true;
	if (*c == 'h' && FLAGS.h == true)
		FLAGS.hh = true;
	if (*c == 'h')
		FLAGS.h = !FLAGS.h;
	if (*c == 'l' && FLAGS.l == true)
		FLAGS.ll = true;
	if (*c == 'l')
		FLAGS.l = !FLAGS.l;
	if (*c == 'j')
		FLAGS.j = true;
	if (*c == 'z')
		FLAGS.z = true;
	if (*c == ' ')
		FLAGS.space = true;
	if (*c == '.')
		ft_setprecision(buffer, c);
}
