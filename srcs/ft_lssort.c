/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lssort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:53:21 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 15:00:47 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_files	**ft_lsnsort(t_files **list, size_t size)
{
	t_files		*tmp;
	size_t		i;
	bool		issorted;

	issorted = false;
	while (!issorted)
	{
		issorted = true;
		i = 1;
		while (i < size)
		{
			if (ft_strcmp(list[i - 1]->name, list[i]->name) > 0)
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

static t_files	**ft_lstsort(t_files **list, size_t size)
{
	t_files		*tmp;
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

static t_files	**ft_lsrev(t_files **list, size_t size)
{
	t_files		**list2;
	size_t		i;

	if ((list2 = (t_files **)malloc(size * sizeof(t_files *))) == NULL)
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

void			ft_lssort(t_ls_flags *flags)
{
	t_files		*tmp;
	size_t		i;
	t_files		**list;

	if (!flags->f && ACTFILE->name)
	{
		i = 0;
		tmp = ACTFILE;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		list = ft_lstab(flags, i);
		list = ft_lsnsort(list, i);
		if (flags->t)
			list = ft_lstsort(list, i);
		if (flags->r)
			list = ft_lsrev(list, i);
		ACTFILE = ft_lsuntab(&list, i);
	}
}
