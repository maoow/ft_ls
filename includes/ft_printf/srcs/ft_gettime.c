/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:32:52 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/08 16:37:30 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <time.h>

char			*g_month[12] = {
	"Jan ",
	"Feb ",
	"Mar ",
	"Apr ",
	"May ",
	"Jun ",
	"Jul ",
	"Aug ",
	"Sep ",
	"Oct ",
	"Nov ",
	"Dec "
};

static void		ft_gethour(t_buf_f *buffer, t_time *ttime, long timestamp)
{
	char	*str;
	time_t	today;

	time(&today);
	if (!FLAGS.l || today - timestamp < 180 * 24 * 60 * 60)
	{
		ft_buffit(buffer, " ", 1);
		str = ft_itoa(ttime->hour);
		ft_buffit(buffer, "00", 2 - ft_strlen(str));
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
		str = ft_itoa(ttime->minute);
		ft_buffit(buffer, ":00", 3 - ft_strlen(str));
		ft_buffit(buffer, str, ft_strlen(str));
	}
	else
	{
		ft_buffit(buffer, "  ", 2);
		str = ft_itoa(ttime->year);
		ft_buffit(buffer, "    ", 4 - ft_strlen(str));
		ft_buffit(buffer, str, ft_strlen(str));
	}
	free(str);
}

char			*ft_gettime(t_buf_f *buffer, va_list ap, char *format)
{
	t_time	*time;
	char	*str;
	long	timestamp;

	timestamp = 0;
	time = NULL;
	if (FLAGS.l)
		timestamp = va_arg(ap, long);
	else
		time = va_arg(ap, t_time *);
	time = ft_timeset(time, timestamp);
	ft_buffit(buffer, g_month[time->month - 1], 4);
	str = ft_itoa(time->day);
	ft_buffit(buffer, "   ", 2 - ft_strlen(str));
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	ft_gethour(buffer, time, timestamp);
	free(time);
	return (format);
}
