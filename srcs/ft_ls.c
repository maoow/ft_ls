/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:47 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/19 18:03:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	ft_initlsflags(t_ls_flags *flags)
{
	flags->l= false;
	flags->R= false;
	flags->a= false;
	flags->r= false;
	flags->t= false;
	flags->error= false;
	flags->first= true;
}

static void		ft_displsusage(char *str)
{
	str++;
	ft_printf("ft_ls: illegal option -- %s\nusage : ft_ls [-Ralrt] [file ...]",str);
	exit(1);
}

static void	ft_setlsflags(char *str, t_ls_flags *flags)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			flags->l= true;
		else if (str[i] == 'R')
			flags->R= true;
		else if (str[i] == 'a')
			flags->a= true;
		else if (str[i] == 'r')
			flags->r= true;
		else if (str[i] == 't')
			flags->t= true;
		else 
			ft_displsusage(str);
		i++;
	}
}

static	void	ft_setdir(char *str, t_ls_flags *flags)
{
	t_dir	*tmp;
	DIR		*dir;

	dir = NULL;
	dir = opendir(str);
	if (dir)
	{
		if (flags->dir->actual == NULL)
		{
			flags->dir->actual = opendir(str);
			flags->dir->path = ft_strdup(str);
		}
		else
		{
			tmp = flags->dir;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = (t_dir *)malloc(sizeof(t_dir));
			tmp = tmp->next;
			tmp->actual = opendir(str);
			tmp->path = ft_strdup(str);
			tmp->next = NULL;
		}
	}
	else
	{
		ft_printf("ft_ls: %s: No such file or directory\n", str);
		flags->error = true;
	}
}

static	void	ft_getlsflags(char *str, t_ls_flags *flags)
{
	if (str[0] == '-')
		ft_setlsflags(str, flags);
	else
		ft_setdir(str, flags);;
}

int				main(int ac, char **av)
{
	int			i;
	t_ls_flags	flags;

	flags.dir = (t_dir *)malloc(sizeof(t_dir));
	flags.dir->actual = NULL;
	flags.dir->next = NULL;
	ft_initlsflags(&flags);
	i = 1;
	while (i < ac)
	{
		ft_getlsflags(av[i], &flags);
		i++;
	}
	if (flags.dir->actual == NULL && !flags.error)
	{
		flags.dir->actual = opendir(".");
		flags.dir->path = ft_strdup(".");
		flags.dir->next = NULL;
	}
	while (flags.dir && !flags.error)
	{
		ft_display(&flags);
		flags.first = false;
		flags.dir = flags.dir->next;
	}
}
