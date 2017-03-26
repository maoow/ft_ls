/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lswidth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:22:14 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 14:28:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_initwidths(t_ls_flags *flags)
{
	flags->sizew = 0;
	flags->linksw = 0;
	flags->uidw = 0;
	flags->gidw = 0;
	flags->namew = 0;
}

void			ft_setminwidthb(t_ls_flags *flags, char **str)
{
	char		*tmp;
	char		*tmp2;

	tmp = ft_itoa(flags->linksw);
	tmp2 = ft_strdup("%c%#b  %");
	str[1] = ft_strjoinfree(&tmp2, &tmp, ALL);
	tmp2 = ft_strdup("ld %");
	str[1] = ft_strjoinfree(&str[1], &tmp2, ALL);
	tmp2 = ft_itoa(flags->uidw);
	str[1] = ft_strjoinfree(&str[1], &tmp2, ALL);
	tmp2 = ft_strdup("-s  %");
	str[1] = ft_strjoinfree(&str[1], &tmp2, ALL);
	tmp2 = ft_itoa(flags->gidw);
	str[1] = ft_strjoinfree(&str[1], &tmp2, ALL);
	tmp2 = ft_strdup("-s %4d,%4d %lk %s%s\n");
	str[1] = ft_strjoinfree(&str[1], &tmp2, ALL);
	if (flags->sizew == 0 || flags->linksw == 0 || flags->uidw == 0)
		flags->dir->blocks = -1;
}

char			**ft_setminwidth(t_ls_flags *flags)
{
	char		**str;
	char		*tmp;
	char		*tmp2;

	if (!(str = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tmp = ft_itoa(flags->linksw);
	tmp2 = ft_strdup("%c%#b  %");
	str[0] = ft_strjoinfree(&tmp2, &tmp, ALL);
	tmp2 = ft_strdup("ld %");
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_itoa(flags->uidw);
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_strdup("-s  %");
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_itoa(flags->gidw);
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_strdup("-s  %");
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_itoa(flags->sizew);
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	tmp2 = ft_strdup("lld %lk %s%s\n");
	str[0] = ft_strjoinfree(&str[0], &tmp2, ALL);
	ft_setminwidthb(flags, str);
	return (str);
}

int				ft_itoalen(int nb)
{
	int		i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char			**ft_getminwidth(t_ls_flags *flags)
{
	t_files		*tmp;

	ft_initwidths(flags);
	tmp = ACTFILE;
	while (tmp)
	{
		if (tmp->name && tmp->uid && tmp->gid && tmp->name[0] &&
				(tmp->name[0] != '.' || flags->a))
		{
			if (ft_itoalen(tmp->size) > flags->sizew)
				flags->sizew = ft_itoalen(tmp->size);
			if (ft_itoalen(tmp->links) > flags->linksw)
				flags->linksw = ft_itoalen(tmp->links);
			if (tmp->uid && ft_strlen(tmp->uid) > flags->uidw)
				flags->uidw = ft_strlen(tmp->uid);
			if (tmp->gid && ft_strlen(tmp->gid) > flags->gidw)
				flags->gidw = ft_strlen(tmp->gid);
			if (ft_strlen(tmp->name) > flags->namew)
				flags->namew = ft_strlen(tmp->name);
			if (tmp->id != 0)
				flags->sizew = 8;
		}
		tmp = tmp->next;
	}
	return (ft_setminwidth(flags));
}
