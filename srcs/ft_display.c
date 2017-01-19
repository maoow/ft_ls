/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:21:27 by cbinet            #+#    #+#             */
/*   Updated: 2017/01/19 18:47:09 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_adddir(t_ls_flags *flags, struct dirent *directory)
{
	t_dir	*tmp;
	DIR		*dir;
	char	*str;
	char	*stmp;

	str = ft_strdup(flags->dir->path);
	stmp = ft_strjoin(str,"/");
	free(str);
	str = ft_strjoin(stmp, directory->d_name);
	dir = NULL;
	dir = opendir(str);
	if (dir != NULL)
	{
		tmp = flags->dir;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_dir *)malloc(sizeof(t_dir));
		tmp->next->actual = dir;
		tmp->next->path = ft_strdup(str);
		tmp->next->next = NULL;
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", directory->d_name);
}

void	ft_longdisplay(t_ls_flags *flags, struct dirent	*directory)
{
	struct stat		stats;

	while (directory)
	{
		if (directory->d_name[0] != '.' || flags->a)
		{
			if(lstat(directory->d_name, &stats) == 0)
			{
				ft_printf("%d%#b % 3ld %s  %s % 6lld %lk %s\n", directory->d_type, stats.st_mode,stats.st_nlink,
						(getpwuid(stats.st_uid))->pw_name,
						(getgrgid(stats.st_gid))->gr_name,
						stats.st_size, (long)stats.st_mtime,directory->d_name);
			}
		}
			if (directory->d_type == 4 && flags->R && directory->d_name[0] != '.')
				ft_adddir(flags, directory);
		directory = readdir(flags->dir->actual);
	}
}

void	ft_display(t_ls_flags *flags)
{
	struct dirent	*directory;
	int				i;

	i = 0;
	if (!flags->first)
		ft_printf("\n%s:\n", flags->dir->path);
	directory = readdir(flags->dir->actual);
	if (!flags->l)
		while ( directory)
		{
			//if (i > 0 && (i % 5) == 0)
				//ft_printf("\n");
			if (directory->d_name[0] != '.' || flags->a)
			{
				i++;
				ft_printf("%s", directory->d_name);
				ft_printf("\n");
			}
			if (directory->d_type == 4 && flags->R && directory->d_name[0] != '.')
				ft_adddir(flags, directory);
			directory = readdir(flags->dir->actual);
		}
	if (flags->l)
		ft_longdisplay(flags, directory);
}



