/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lslongset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:09:20 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 13:49:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_printerror(t_ls_flags *flags, t_files *tmp, char **strtmp)
{
	if ((ft_strcmp(".", tmp->name) != 0 && ft_strcmp("..", tmp->name) != 0)
			|| flags->a)
		perror(ft_strjoin("ft_ls: ", tmp->name));
	if (ft_strcmp(".", tmp->name) == 0)
		perror(ft_strjoin("ft_ls: ", ft_strrchr(flags->dir->path, '/')
					+ 1));
	free(*strtmp);
}

bool			ft_setllsfiles(t_ls_flags *flags, t_files *tmp, struct dirent
		*directory)
{
	struct stat		stats;
	char			*strtmp;

	strtmp = ft_strjoin(flags->dir->path, "/");
	strtmp = ft_strjoinfree(&strtmp, &(tmp->name), FIRST);
	if (lstat(strtmp, &stats) != 0)
	{
		if (stat(strtmp, &stats) == 0)
		{
			ft_setlsgenerals(tmp, stats, flags, directory);
			free(strtmp);
			return (true);
		}
		ft_printerror(flags, tmp, &strtmp);
		return (false);
	}
	else
	{
		ft_setlsgenerals(tmp, stats, flags, directory);
		free(strtmp);
		return (true);
	}
}
