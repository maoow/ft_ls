/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:43:17 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/08 16:37:31 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_time	*ft_timesetyear(t_time *time)
{
	long	tmpts;

	tmpts = time->timestamp;
	while (tmpts >= DAY_TIME * 365 &&
			(tmpts > DAY_TIME * 365 || (time->year - 1970) % 4 != 2))
	{
		if ((time->year - 1970) % 4 != 2)
			tmpts -= DAY_TIME * 365;
		else
			tmpts -= DAY_TIME * 366;
		time->year++;
	}
	time->timestamp = tmpts;
	return (time);
}

t_time	*ft_timesetmonth(t_time *time)
{
	long	tmpts;

	tmpts = time->timestamp;
	while (tmpts >= DAY_TIME * 28 &&
			(tmpts >= DAY_TIME * 29 || (time->year - 1970) % 4 != 2)
			&& (tmpts >= DAY_TIME * 30 || time->month == 2)
			&& (tmpts >= DAY_TIME * 31 || (time->month <= 7 && time->month % 2
					== 0) || (time->month > 7 && time->month % 2 == 1)))
	{
		if ((time->year - 1970) % 4 == 2 && time->month == 2)
			tmpts -= DAY_TIME * 29;
		else if ((time->year - 1970) % 4 != 2 && time->month == 2)
			tmpts -= DAY_TIME * 28;
		else if ((time->month <= 7 && time->month % 2 == 1) ||
				(time->month > 7 && time->month % 2 == 0))
			tmpts -= DAY_TIME * 31;
		else
			tmpts -= DAY_TIME * 30;
		time->month++;
	}
	time->timestamp = tmpts;
	return (time);
}

t_time	*ft_timesetday(t_time *time)
{
	long	tmpts;

	tmpts = time->timestamp;
	while (tmpts >= DAY_TIME)
	{
		tmpts -= DAY_TIME;
		time->day++;
	}
	time->timestamp = tmpts;
	return (time);
}

t_time	*ft_timesethour(t_time *time)
{
	long	tmpts;

	tmpts = time->timestamp;
	while (tmpts >= 3600)
	{
		tmpts -= 3600;
		time->hour++;
	}
	time->timestamp = tmpts;
	time->minute = (time->timestamp / 60);
	time->timestamp -= (time->minute) * 60;
	time->second = time->timestamp;
	time->timestamp = 0;
	return (time);
}

t_time	*ft_timeset(t_time *time, long timestamp)
{
	if (timestamp)
	{
		timestamp += 3600;
		time = (t_time *)malloc(sizeof(*time));
		time->year = 1970;
		time->month = 1;
		time->day = 1;
		time->hour = 0;
		time->minute = 0;
		time->second = 0;
		time->timestamp = timestamp;
		time = ft_timesetyear(time);
		time = ft_timesetmonth(time);
		time = ft_timesetday(time);
		time = ft_timesethour(time);
	}
	return (time);
}
