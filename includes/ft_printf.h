/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:08:37 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/04 16:49:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../srcs/libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# define BUFF_SIZE 2048
# define FLAGS buffer->flags
# define DAY_TIME 86400

typedef struct	s_flags_f
{
	bool		sharp;
	bool		zero;
	bool		m;
	bool		p;
	bool		pp;
	bool		hh;
	bool		h;
	bool		l;
	bool		ll;
	bool		j;
	bool		z;
	bool		space;
	bool		isprecision;
	int			precision;
	int			minimum;
	bool		string;
	bool		signe;
	bool		uppercase;
}				t_flags_f;

typedef struct	s_buf_f
{
	char		buf[BUFF_SIZE];
	int			cursor;
	int			total;
	t_flags_f	flags;
}				t_buf_f;

typedef struct	s_time_f
{
	long		time;
	int			year;
	int			month;
	int			day;
	int			hour;
	int			minute;
	int			second;
}				t_time_f;

typedef struct	s_time
{
	long		timestamp;
	int			year;
	int			month;
	int			day;
	int			hour;
	int			minute;
	int			second;
}				t_time;

char			*ft_plusit(t_buf_f *buffer, char *str);
char			*ft_getstrptr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getbool(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getbits(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getcolor(t_buf_f *buffer, va_list ap, char *format);
void			ft_colorize(t_buf_f *buffer, va_list ap, char *format);
void			ft_bufwcharfour(t_buf_f *buffer, int c);
void			ft_bufwcharthree(t_buf_f *buffer, int c);
void			ft_bufwchartwo(t_buf_f *buffer, int c);
int				ft_bufwchar(t_buf_f *buffer, int c);
char			*ft_flagit(t_buf_f *buffer, char *str);
char			*ft_getpercent(t_buf_f *buffer, va_list ap, char *format);
char			*ft_gettime(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getstr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getsstr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getptr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_nulnbr(t_buf_f *buffer, char *format);
char			*ft_getnbr(t_buf_f *buffer, va_list ap, char *format);
void			ft_setflags(t_buf_f *buffer, char *c);
char			*ft_getlnbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getmnbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getllnbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getnbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getoctal(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getloctal(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getmoctal(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getunbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getcursor(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getumnbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getlunbr(t_buf_f *buffer, va_list ap, char *format);
char			*ft_gethexa(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getlhexa(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getllhexa(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getchar(t_buf_f *buffer, va_list ap, char *format);
char			*ft_getwchar(t_buf_f *buffer, va_list ap, char *format);
void			ft_initbufferf(t_buf_f *buffer);
void			ft_putbuf(t_buf_f *buffer);
void			ft_buffit(t_buf_f *buffer, char *str, int size);
void			ft_intbuffit(t_buf_f *buffer, unsigned int *str, int size);
void			ft_getf(t_buf_f *buffer, va_list ap, char *format);
t_time			*ft_timeset(t_time *time, long timestamp);
bool			ft_isconv(char c);
void			*getconv(char c);
char			*convarg(t_buf_f *buffer, va_list ap, char *format);
char			*ft_initstr(t_buf_f *buffer, char *str);
char			*ft_placestr(t_buf_f *buffer, char *str, char *dst);
int				ft_printf(const char *format, ...);
#endif
