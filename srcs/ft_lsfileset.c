/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsfileset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:42:19 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 14:46:59 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <errno.h>

void	ft_pushdirerror(struct dirent *directory, t_dir *tmp)
{
	char *str;
	char *strtmp;

	str = ft_strdup(": ");
	strtmp = strerror(errno);
	strtmp = ft_strjoinfree(&str, &strtmp, FIRST);
	tmp->next->error = ft_strjoin(directory->d_name, strtmp);
	free(strtmp);
}

void	ft_pushdir(t_ls_flags *flags, char *str, struct dirent *directory,
		t_files *ftmp)
{
	DIR		*dir;
	t_dir	*tmp;

	dir = opendir(str);
	tmp = flags->dir;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->next == NULL)
		tmp->next = (t_dir *)malloc(sizeof(t_dir));
	tmp->next->actual = dir;
	tmp->next->time = ftmp->time;
	tmp->next->path = ft_strdup(str);
	tmp->next->files = NULL;
	tmp->next->real = true;
	tmp->next->next = NULL;
	if (dir != NULL)
		tmp->next->error = NULL;
	else
	{
		ft_pushdirerror(directory, tmp);
	}
}

void	ft_adddir(t_ls_flags *flags, struct dirent *directory)
{
	char	*str;
	char	*stmp;
	t_files *ftmp;

	ftmp = ACTFILE;
	while (ftmp->next)
		ftmp = ftmp->next;
	stmp = ft_strjoin(flags->dir->path, "/");
	str = ft_strjoin(stmp, directory->d_name);
	free(stmp);
	ft_pushdir(flags, str, directory, ftmp);
	free(str);
}

t_files	*ft_findfile(t_ls_flags *flags)
{
	t_files *tmp;

	if (ACTFILE == NULL)
	{
		if (!(ACTFILE = (t_files *)malloc(sizeof(t_files))))
			return (NULL);
		tmp = ACTFILE;
	}
	else
	{
		tmp = ACTFILE;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_files *)malloc(sizeof(t_files))))
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

bool	ft_setlsfiles(t_ls_flags *flags, struct dirent *directory)
{
	t_files *tmp;

	tmp = NULL;
	while (!tmp)
		tmp = ft_findfile(flags);
	tmp->name = ft_strdup(directory->d_name);
	tmp->next = NULL;
	tmp->uid = NULL;
	tmp->gid = NULL;
	tmp->link = NULL;
	tmp->color = NULL;
	tmp->ctype = '-';
	tmp->size = 0;
	tmp->links = 0;
	if (!ft_setllsfiles(flags, tmp, directory))
	{
		free(tmp->name);
		tmp->name = NULL;
		return (false);
	}
	if (tmp->perm < 16640)
		return (false);
	return (true);
}
