/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:47 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:09:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

bool		ft_isdirectory(t_ls_flags *flags)
{
	t_files		*tmp;

	tmp = ACTFILE;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->ctype == 'd')
			return (true);
	}
	return (false);
}

void		ft_displsusage(char *str, t_ls_flags *flags)
{
	write(2, flags->name, ft_strlen(flags->name));
	write(2, ": illegal option -- ", 20);
	write(2, str, 1);
	write(2, "\nusage : ft_ls [-RalrtfGu1] [file ...]\n", 39);
	exit(1);
}

static void	ft_browse(t_ls_flags *flags)
{
	t_dir		*tmpdir;

	while (flags->dir)
	{
		if (!flags->f)
			ft_lssortdir(flags);
		ft_display(flags);
		flags->first = false;
		tmpdir = flags->dir;
		flags->dir = flags->dir->next;
		ft_freedir(flags, &tmpdir);
	}
	free(flags->name);
}

int			main(int ac, char **av)
{
	int			i;
	t_ls_flags	flags;

	ft_initlsflags(&flags, av[0]);
	if (!(flags.dir = (t_dir *)malloc(sizeof(t_dir))))
		return (-1);
	flags.dir->actual = NULL;
	flags.dir->next = NULL;
	flags.dir->error = NULL;
	flags.dir->files = NULL;
	i = 1;
	while (i < ac)
	{
		ft_getlsflags(ft_strdup(av[i]), &flags);
		i++;
	}
	if (flags.dir->actual == NULL && !flags.error)
	{
		flags.dir->actual = opendir(".");
		flags.dir->path = ft_strdup(".");
		flags.dir->real = true;
		flags.dir->next = NULL;
	}
	if (flags.dir->actual)
		ft_browse(&flags);
}
