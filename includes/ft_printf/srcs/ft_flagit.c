/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:59:51 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/10 18:22:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_plusstr(t_buf_f *buffer, char *str)
{
	if (str[0] != '+' && str[0] != '-')
	{
		str = ft_plusit(buffer, str);
		FLAGS.pp = true;
	}
	return (str);
}

static char		*ft_spacestr(t_buf_f *buffer, char *str)
{
	char	*dst;

	if (FLAGS.p && FLAGS.signe)
		str = ft_plusstr(buffer, str);
	if (!FLAGS.p && FLAGS.space)
	{
		if (str[0] == '0' && FLAGS.signe)
		{
			str[0] = ' ';
			dst = str;
		}
		else if (str[0] == ' ')
			return (str);
		else if (FLAGS.signe)
		{
			dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(*dst));
			dst[0] = ' ';
			ft_strcpy(dst + 1, str);
			free(str);
			return (dst);
		}
	}
	if (FLAGS.p && FLAGS.signe)
		return (ft_plusstr(buffer, str));
	return (str);
}

char			*ft_mallocflag(t_buf_f *buffer, char *str)
{
	if (FLAGS.string || FLAGS.minimum > FLAGS.precision)
	{
		if ((str = (char *)malloc((FLAGS.minimum + 1) * sizeof(*str)))
				== NULL)
			return (NULL);
		str[FLAGS.minimum] = '\0';
	}
	else if ((str = (char *)malloc((FLAGS.precision + 1) * sizeof(*str)))
			== NULL)
		return (NULL);
	str[FLAGS.precision] = '\0';
	return (str);
}

char			*ft_typeit(t_buf_f *buffer, char *str)
{
	char	*dst;
	int		i;

	if (FLAGS.signe)
		return (str);
	if (FLAGS.zero && str[0] == '0' && str[1] == '0')
	{
		str[1] = 'X';
		if (!FLAGS.uppercase)
			str[1] = 'x';
		return (str);
	}
	i = 1;
	if ((dst = (char *)malloc((ft_strlen(str) + 3) * sizeof(*dst))) == NULL)
		return (NULL);
	dst[0] = '0';
	dst[1] = 'X';
	if (!FLAGS.uppercase)
		dst[1] = 'x';
	while (str[++i - 2])
		dst[i] = str[i - 2];
	dst[i] = '\0';
	free(str);
	return (dst);
}

char			*ft_flagit(t_buf_f *buffer, char *str)
{
	char	*dst;

	dst = NULL;
	if (FLAGS.string && FLAGS.isprecision && FLAGS.precision < ft_strlen(str))
		str[FLAGS.precision] = '\0';
	if (FLAGS.m && !FLAGS.sharp)
		FLAGS.zero = false;
	if (FLAGS.sharp && FLAGS.precision < FLAGS.minimum && !FLAGS.zero)
		str = ft_typeit(buffer, str);
	if (FLAGS.minimum > ft_strlen(str) || FLAGS.precision > ft_strlen(str))
	{
		dst = ft_mallocflag(buffer, dst);
		dst = ft_initstr(buffer, dst);
		dst = ft_placestr(buffer, str, dst);
		if (str[0] != '-' && FLAGS.signe)
			dst = ft_spacestr(buffer, dst);
		free(str);
		str = dst;
	}
	if (FLAGS.sharp && (FLAGS.precision >= FLAGS.minimum || FLAGS.zero))
		str = ft_typeit(buffer, str);
	if (!FLAGS.sharp || (FLAGS.precision || FLAGS.minimum))
		str = ft_spacestr(buffer, str);
	return (str);
}
