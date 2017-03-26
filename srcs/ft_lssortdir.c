/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssortdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:27:24 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:04:05 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir			**ft_lstsortdir(t_dir **list, size_t size)
{
	t_dir		*tmp;
	size_t		i;
	bool		issorted;

	issorted = false;
	while (!issorted)
	{
		issorted = true;
		i = 1;
		while (i < size)
		{
			if (list[i - 1]->time < list[i]->time)
			{
				issorted = false;
				tmp = list[i - 1];
				list[i - 1] = list[i];
				list[i] = tmp;
			}
			i++;
		}
	}
	return (list);
}

t_dir			**ft_lsdirrev(t_dir **list, size_t size)
{
	t_dir		**list2;
	size_t		i;

	if ((list2 = (t_dir **)malloc(size * sizeof(t_dir *))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		list2[size - i - 1] = list[i];
		i++;
	}
	free(list);
	return (list2);
}

t_dir			**ft_lsnsortdir(t_dir **list, size_t size)
{
	t_dir		*tmp;
	size_t		i;
	bool		issorted;

	issorted = false;
	while (!issorted)
	{
		issorted = true;
		i = 1;
		while (i < size)
		{
			if (ft_strcmp(list[i - 1]->path, list[i]->path) > 0)
			{
				issorted = false;
				tmp = list[i - 1];
				list[i - 1] = list[i];
				list[i] = tmp;
			}
			i++;
		}
	}
	return (list);
}

size_t			ft_dirlen(t_ls_flags *flags)
{
	t_dir	*tmp;
	size_t	i;

	i = 0;
	tmp = flags->dir;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void			ft_lssortdir(t_ls_flags *flags)
{
	t_dir	**list;
	int		size;

	size = ft_dirlen(flags);
	list = ft_lsdirtab(flags, size);
	if (flags->t && flags->dir && !flags->error && !flags->f)
		list = ft_lstsortdir(list, size);
	else if (!flags->f)
		list = ft_lsnsortdir(list, size);
	if (flags->r && flags->dir && !flags->f)
		list = ft_lsdirrev(list, size);
	flags->dir = ft_lsdiruntab(&list, size);
}
