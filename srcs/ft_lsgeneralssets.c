/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsgeneralssets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:41:52 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 13:49:39 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	g_ctype[9] =
{
	'b',
	'c',
	'd',
	'p',
	'l',
	'-',
	's',
	'f',
	'h'
};

char	g_type[8] =
{
	DT_BLK,
	DT_CHR,
	DT_DIR,
	DT_FIFO,
	DT_LNK,
	DT_REG,
	DT_SOCK,
	DT_UNKNOWN
};

void			ft_settype(t_files *tmp, struct stat stats)
{
	if (S_ISREG(stats.st_mode))
		tmp->ctype = '-';
	if (S_ISDIR(stats.st_mode))
	{
		tmp->ctype = 'l';
		if (ft_strcmp(tmp->link, "") == 0)
			tmp->ctype = 'd';
	}
	if (S_ISCHR(stats.st_mode))
		tmp->ctype = 'c';
	if (S_ISBLK(stats.st_mode))
		tmp->ctype = 'b';
	if (S_ISFIFO(stats.st_mode))
		tmp->ctype = 'p';
	if (S_ISLNK(stats.st_mode))
		tmp->ctype = 'l';
	if (S_ISSOCK(stats.st_mode))
		tmp->ctype = 's';
}

void			ft_setlsids(t_ls_flags *flags, t_files *tmp, struct stat stats)
{
	struct passwd	*pass;
	struct group	*grp;

	tmp->id = stats.st_rdev;
	if (tmp->ctype == 'f')
		ft_settype(tmp, stats);
	if (flags->a || tmp->name[0] != '.')
	{
		if ((pass = getpwuid(stats.st_uid)) && pass->pw_name)
			tmp->uid = ft_strdup(pass->pw_name);
		else
			tmp->uid = ft_itoa(stats.st_uid);
		if ((grp = getgrgid(stats.st_gid)) && grp->gr_name)
			tmp->gid = ft_strdup(grp->gr_name);
		else
			tmp->gid = ft_itoa(stats.st_gid);
	}
}

bool			ft_setlslinks(t_ls_flags *flags, t_files *tmp)
{
	int				i;
	char			str[1024];
	char			*strtmp;

	strtmp = ft_strjoin(flags->dir->path, "/");
	strtmp = ft_strjoinfree(&strtmp, &(tmp->name), FIRST);
	if ((i = readlink(strtmp, str, 1024)) != -1)
	{
		str[i] = '\0';
		tmp->link = ft_strjoin(" -> ", str);
		free(strtmp);
		return (true);
	}
	else
		tmp->link = ft_strdup("");
	free(strtmp);
	return (false);
}

static void		ft_setlscolors(t_files *tmp, t_ls_flags *flags)
{
	if (tmp->ctype == 'd' && flags->gg && (tmp->name[0] != '.' || flags->a))
		tmp->color = ft_strdup("\033[34m");
	else if (tmp->ctype == 'b' && flags->gg && (tmp->name[0] != '.' ||
				flags->a))
		tmp->color = ft_strdup("\033[46m\033[34m");
	else if (tmp->ctype == 'c' && flags->gg && (tmp->name[0] != '.' ||
				flags->a))
		tmp->color = ft_strdup("\033[43m\033[34m");
	else if (tmp->ctype == 'l' && flags->gg && (tmp->name[0] != '.' ||
				flags->a))
		tmp->color = ft_strdup("\033[35m");
	else if (((tmp->perm / 64) % 2 == 1) && flags->gg && (tmp->name[0] != '.'
				|| flags->a))
		tmp->color = ft_strdup("\033[31m");
	else
		tmp->color = ft_strdup("");
}

void			ft_setlsgenerals(t_files *tmp, struct stat stats,
		t_ls_flags *flags, struct dirent *directory)
{
	int				i;

	i = 0;
	tmp->perm = stats.st_mode;
	if (flags->rr || flags->gg || flags->l)
	{
		tmp->type = directory->d_type;
		while (g_type[i] != tmp->type && i < 8)
			i++;
		tmp->ctype = g_ctype[i];
		tmp->links = stats.st_nlink;
		tmp->size = stats.st_size;
		ft_setlslinks(flags, tmp);
		ft_setlsids(flags, tmp, stats);
	}
	tmp->time = stats.st_atime;
	if ((flags->t || flags->l) && !flags->u)
		tmp->time = stats.st_mtime;
	if (tmp->name[0] != '.' || flags->a)
		flags->dir->blocks += stats.st_blocks;
	if (flags->gg)
		ft_setlscolors(tmp, flags);
}
