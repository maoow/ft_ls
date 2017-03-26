/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:24:45 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 14:36:32 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_getlsflags(char *str, t_ls_flags *flags)
{
	if (str[0] == '-')
	{
		if (flags->option)
			ft_setlsflags(str, flags);
		else
		{
			write(2, "ft_ls: ", 7);
			write(2, str, ft_strlen(str));
			write(2, ": No such file or directory\n", 28);
			flags->first = false;
		}
	}
	else
	{
		ft_setpath(str, flags);
		flags->option = false;
	}
	free(str);
}

void		ft_initlsflags(t_ls_flags *flags, char *str)
{
	flags->name = ft_strdup(str);
	flags->namew = 0;
	flags->linksw = 0;
	flags->uidw = 0;
	flags->gidw = 0;
	flags->sizew = 0;
	flags->dir = NULL;
	flags->l = false;
	flags->rr = false;
	flags->right = false;
	flags->a = false;
	flags->r = false;
	flags->gg = false;
	flags->f = false;
	flags->u = false;
	flags->t = false;
	flags->error = false;
	flags->first = true;
	flags->option = true;
}

void		ft_setlsflags(char *str, t_ls_flags *flags)
{
	while (*(str + 1))
	{
		str++;
		if (*str == 'f')
			flags->f = true;
		if (*str == 'G')
			flags->gg = true;
		else if (*str == 'f' || *str == 'a')
			flags->a = true;
		else if (*str == 'u')
			flags->u = true;
		else if (*str == 'l')
			flags->l = true;
		else if (*str == 'R')
			flags->rr = true;
		else if (*str == 'r')
			flags->r = true;
		else if (*str == 't')
			flags->t = true;
		else if (*str == '1')
			flags->l = false;
		else
			ft_displsusage(str, flags);
	}
}

static void	ft_setdir(char *str, t_ls_flags *flags, DIR *dir)
{
	t_dir	*tmp;

	if (flags->dir->actual == NULL)
		tmp = flags->dir;
	else
	{
		flags->first = false;
		tmp = flags->dir;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->next == NULL)
			tmp->next = (t_dir *)malloc(sizeof(t_dir));
		tmp = tmp->next;
	}
	tmp->actual = dir;
	if (ft_strcmp(str, "/") == 0)
		str[0] = '\0';
	tmp->path = ft_strdup(str);
	tmp->next = NULL;
	tmp->error = NULL;
	tmp->real = true;
	tmp->files = NULL;
}

void		ft_setpath(char *str, t_ls_flags *flags)
{
	DIR		*dir;
	t_dir	*tmp;

	dir = NULL;
	dir = opendir(str);
	if (dir)
		ft_setdir(str, flags, dir);
	else if (!ft_addfile(str, flags))
	{
		tmp = flags->dir;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp != flags->dir)
			free(tmp);
		else if (flags->dir && flags->dir->actual)
		{
			closedir(flags->dir->actual);
			flags->dir->actual = NULL;
		}
		perror(ft_strjoin("ft_ls :", str));
		flags->error = true;
		flags->first = false;
	}
}
