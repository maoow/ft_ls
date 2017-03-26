/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:45:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/07 23:24:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*g_col[9] = {
	"black",
	"red",
	"green",
	"yellow",
	"blue",
	"pink",
	"cyan",
	"grey",
	"eoc"
};

char	*ft_getcolor(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	int		j;
	char	*str;
	bool	color;

	color = false;
	i = 0;
	j = 0;
	while (format[i] != '}')
		i++;
	str = ft_strsub(format, 1, i - 1);
	while (j < 9)
	{
		if (ft_strcmp(str, g_col[j]) == 0 || ft_strcmp(str + 2, g_col[j]) == 0)
			color = true;
		j++;
	}
	free(str);
	if (color == true)
	{
		ft_colorize(buffer, ap, str);
		return (format + i);
	}
	ft_buffit(buffer, "{", 1);
	return (format);
}

void	ft_colorize(t_buf_f *buffer, va_list ap, char *format)
{
	char	str[2];
	int		i;

	i = 0;
	str[0] = '3';
	if (*format == 'b' && *(format + 1) == 'g')
	{
		str[0] = '4';
		format += 2;
	}
	str[1] = 0;
	while (i < 8)
	{
		if (ft_strcmp(format, g_col[i]) == 0)
			str[1] = i + '0';
		i++;
	}
	ft_buffit(buffer, "\033[", 2);
	if (str[1] != 0)
		ft_buffit(buffer, str, 2);
	else
		ft_buffit(buffer, "0", 1);
	ft_buffit(buffer, "m", 1);
	if (ap)
		str[0] = 0;
}
