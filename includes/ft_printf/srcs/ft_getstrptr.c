/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstrptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:33:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/10 18:44:41 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_getcell(t_buf_f *buffer, char *strtab, bool m)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen(strtab);
	FLAGS.string = true;
	str = ft_strdup(ft_flagit(buffer, ft_strdup(strtab)));
	if (ft_strlen(str) < size && ft_strlen(str) > 6 && m)
		while (i++ < 3)
			str[ft_strlen(str) - i] = '.';
	ft_buffit(buffer, str, ft_strlen(str));
	if (str)
		free(str);
}

char			*ft_getstrptr(t_buf_f *buffer, va_list ap, char *format)
{
	char	**strtab;
	bool	m;
	char	cut[2];

	cut[0] = ' ';
	cut[1] = ' ';
	if (FLAGS.p)
		cut[1] = '|';
	m = FLAGS.m;
	FLAGS.m = false;
	strtab = va_arg(ap, char **);
	FLAGS.minimum -= 2;
	while (*strtab)
	{
		ft_getcell(buffer, *strtab, m);
		if (*(strtab + 1))
			ft_buffit(buffer, cut, 2);
		strtab++;
	}
	return (format);
}
