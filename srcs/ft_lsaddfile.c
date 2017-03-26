/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsaddfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:53:03 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:03:24 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_dir	*ft_presetfile(t_ls_flags *flags, DIR *dir, char *path,
		struct dirent *directory)
{
	t_dir			*tmpd;

	if (flags->dir->actual == NULL)
		tmpd = flags->dir;
	else
	{
		flags->first = false;
		tmpd = flags->dir;
		while (tmpd->next)
			tmpd = tmpd->next;
		while (tmpd->next == NULL)
			tmpd->next = (t_dir *)malloc(sizeof(t_dir));
		tmpd = tmpd->next;
	}
	tmpd->actual = dir;
	tmpd->path = ft_strdup(path);
	tmpd->next = NULL;
	tmpd->error = NULL;
	tmpd->files = (t_files *)malloc(sizeof(t_files));
	tmpd->files->name = ft_strdup(directory->d_name);
	tmpd->files->next = NULL;
	tmpd->files->color = NULL;
	tmpd->real = false;
	return (tmpd);
}

static void		ft_lsfiletest(t_ls_flags *flags, struct dirent *directory,
		char *path, t_dir *tmpd)
{
	if (ft_strcmp(tmpd->path, "/") == 0)
	{
		free(tmpd->path);
		tmpd->path = ft_strdup("");
	}
	if (flags->dir->files->ctype == 'd')
	{
		flags->dir->real = true;
		free(flags->dir->path);
		flags->dir->path = ft_strjoin(path, directory->d_name);
		flags->dir->error = ft_strjoin(directory->d_name,
				": Permission denied");
		ft_freefile(&(tmpd->files));
	}
	free(path);
}

static bool		ft_lspushfile(t_ls_flags *flags, DIR *dir, char *path,
		struct dirent *directory)
{
	t_dir			*tmpd;
	t_dir			*tmpd2;

	if (directory)
	{
		tmpd = ft_presetfile(flags, dir, path, directory);
		tmpd2 = flags->dir;
		while (flags->dir->next)
			flags->dir = flags->dir->next;
		if (!ft_setllsfiles(flags, tmpd->files, directory))
		{
			ft_freefile(&(tmpd->files));
			tmpd->files = NULL;
			if (tmpd != tmpd2)
			{
				free(tmpd);
				tmpd = NULL;
			}
			return (false);
		}
		ft_lsfiletest(flags, directory, path, tmpd);
		flags->dir = tmpd2;
		return (true);
	}
	return (false);
}

bool			ft_addfile(char *str, t_ls_flags *flags)
{
	char			*tmp;
	char			*path;
	DIR				*dir;
	struct dirent	*directory;

	if (!(tmp = ft_strrchr(str, '/')))
	{
		tmp = str;
		path = ft_strdup(".");
		tmp--;
	}
	else if (tmp != str)
	{
		*tmp = '\0';
		path = ft_strdup(str);
		*tmp = '/';
	}
	else
		path = ft_strdup("/");
	if (!(dir = opendir(path)))
		return (false);
	directory = readdir(dir);
	while (directory && ft_strcmp(tmp + 1, directory->d_name))
		directory = readdir(dir);
	return (ft_lspushfile(flags, dir, path, directory));
}
