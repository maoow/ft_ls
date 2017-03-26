/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:21:27 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:12:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_shortdisplay(t_ls_flags *flags)
{
	char		*color;
	char		*stmp;
	t_files		*ftmp;

	if (!flags->dir->real && ft_strcmp(".", flags->dir->path))
	{
		stmp = ft_strdup("/");
		flags->dir->path = ft_strjoinfree(&flags->dir->path, &stmp, ALL);
		ACTFILE->name = ft_strjoinfree(&(flags->dir->path), &(ACTFILE->name),
				SECOND);
	}
	color = ft_strdup("\033[00m");
	ftmp = ACTFILE;
	while (ftmp && ftmp->name)
	{
		if (flags->gg)
		{
			stmp = ft_strjoinfree(&(ftmp->name), &color, FIRST);
			ftmp->name = ft_strjoinfree(&(ftmp->color), &stmp, SECOND);
		}
		if (ftmp->name[0] != '.' || flags->a || !flags->dir->real)
			ft_printf("%s\n", ftmp->name);
		ftmp = ftmp->next;
	}
	free(color);
}

static void		ft_longprint(t_ls_flags *flags, t_files *ftmp, char *color,
		char **str)
{
	char		*stmp;

	if (ftmp->name && ftmp->uid && ftmp->gid && ftmp->name[0] &&
			(ftmp->name[0] != '.' || flags->a))
	{
		if (flags->gg)
		{
			stmp = ft_strjoinfree(&(ftmp->name), &color, FIRST);
			ftmp->name = ft_strjoinfree(&(ftmp->color), &stmp, SECOND);
		}
		if (ftmp->ctype != 'c' && ftmp->ctype != 'b')
			ft_printf(str[0], ftmp->ctype, ftmp->perm, ftmp->links,
					ftmp->uid, ftmp->gid, ftmp->size, ftmp->time, ftmp->name,
					ftmp->link);
		else
			ft_printf(str[1], ftmp->ctype, ftmp->perm, ftmp->links,
					ftmp->uid, ftmp->gid, major(ftmp->id), minor(ftmp->id),
					ftmp->time, ftmp->name, ftmp->link);
	}
}

void			ft_longdisplay(t_ls_flags *flags)
{
	char		**str;
	char		*stmp;
	t_files		*ftmp;

	str = ft_getminwidth(flags);
	if (flags->dir->real && flags->dir->blocks != -1)
		ft_printf("total %ld\n", flags->dir->blocks);
	else if (ft_strcmp(".", flags->dir->path))
	{
		stmp = ft_strdup("/");
		flags->dir->path = ft_strjoinfree(&(flags->dir->path), &stmp, ALL);
		ACTFILE->name = ft_strjoinfree(&(flags->dir->path), &(ACTFILE->name),
				SECOND);
	}
	ftmp = ACTFILE;
	stmp = ft_strdup("\033[00m");
	while (ftmp)
	{
		ft_longprint(flags, ftmp, stmp, str);
		ftmp = ftmp->next;
	}
	free(str[0]);
	free(str[1]);
	free(str);
	free(stmp);
}

void			ft_browsedir(t_ls_flags *flags, struct dirent *directory)
{
	bool			right;

	while (directory)
	{
		right = ft_setlsfiles(flags, directory);
		if ((ft_isdirectory(flags)) && flags->rr && (flags->a ||
					directory->d_name[0] != '.') && ft_strcmp(directory->d_name,
						"..") != 0 && ft_strcmp(directory->d_name, ".") != 0)
			ft_adddir(flags, directory);
		directory = readdir(flags->dir->actual);
	}
}

void			ft_display(t_ls_flags *flags)
{
	struct dirent	*directory;

	if (!flags->first && flags->dir->real)
		ft_printf("%s:\n", flags->dir->path);
	if (!flags->dir->error && flags->dir->real)
	{
		directory = readdir(flags->dir->actual);
		flags->dir->blocks = 0;
		ft_browsedir(flags, directory);
		if (!flags->f)
			ft_lssort(flags);
	}
	if (flags->dir->error && flags->dir->error[0])
	{
		write(2, "ft_ls: ", 7);
		write(2, flags->dir->error, ft_strlen(flags->dir->error));
		write(2, "\n", 1);
	}
	if (!flags->dir->error && !flags->l)
		ft_shortdisplay(flags);
	if (!flags->dir->error && flags->l)
		ft_longdisplay(flags);
	if (flags->dir->next && (flags->dir->real || flags->dir->next->real))
		ft_printf("\n");
}
