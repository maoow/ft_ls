/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:22:44 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 14:47:40 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_freefile(t_files **tmp)
{
	if ((*tmp) != NULL)
	{
		if ((*tmp)->name)
			free((*tmp)->name);
		if ((*tmp)->uid)
			free((*tmp)->uid);
		if ((*tmp)->gid)
			free((*tmp)->gid);
		if ((*tmp)->link)
			free((*tmp)->link);
		if ((*tmp)->color)
			free((*tmp)->color);
		free((*tmp));
		*tmp = NULL;
	}
}

static void		ft_freeemptfile(t_files **tmpfile)
{
	if ((*tmpfile)->name)
		free((*tmpfile)->name);
	if ((*tmpfile)->color)
		free((*tmpfile)->color);
	if ((*tmpfile)->link)
		free((*tmpfile)->link);
	free(*tmpfile);
}

void			ft_freedir(t_ls_flags *flags, t_dir **tmp)
{
	t_files		*tmpfile;

	if ((*tmp)->actual)
		closedir((*tmp)->actual);
	if ((*tmp)->error)
		free((*tmp)->error);
	if ((*tmp)->path)
		free((*tmp)->path);
	while ((*tmp)->files)
	{
		tmpfile = (*tmp)->files;
		(*tmp)->files = (*tmp)->files->next;
		if (tmpfile->name && (tmpfile->name[0] != '.' || flags->a))
			ft_freefile(&tmpfile);
		else if (tmpfile->name && tmpfile->name[0])
			ft_freeemptfile(&tmpfile);
	}
	if (*tmp)
		free(*tmp);
	*tmp = NULL;
}
