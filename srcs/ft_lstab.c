/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:45:38 by cbinet            #+#    #+#             */
/*   Updated: 2017/03/14 14:59:34 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files	**ft_lstab(t_ls_flags *flags, size_t size)
{
	t_files		**tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (t_files **)malloc(size * sizeof(t_files *))))
		return (NULL);
	while (i < size)
	{
		tmp[i] = ACTFILE;
		i++;
		ACTFILE = NEXTFILE;
	}
	return (tmp);
}

t_files	*ft_lsuntab(t_files ***list, size_t size)
{
	size_t	i;
	t_files	*tmp;

	i = 1;
	while (i < size)
	{
		(*list)[i - 1]->next = (*list)[i];
		i++;
	}
	(*list)[i - 1]->next = NULL;
	tmp = (*list)[0];
	free((*list));
	return (tmp);
}

t_dir	**ft_lsdirtab(t_ls_flags *flags, size_t size)
{
	t_dir		**tmp;
	t_dir		*tmp2;
	size_t		i;

	i = 0;
	tmp2 = flags->dir;
	if (!(tmp = (t_dir **)malloc(size * sizeof(t_dir *))))
		return (NULL);
	while (i < size)
	{
		tmp[i] = tmp2;
		i++;
		tmp2 = tmp2->next;
	}
	return (tmp);
}

t_dir	*ft_lsdiruntab(t_dir ***list, size_t size)
{
	size_t	i;
	t_dir	*tmp;

	i = 1;
	while (i < size)
	{
		(*list)[i - 1]->next = (*list)[i];
		i++;
	}
	(*list)[i - 1]->next = NULL;
	tmp = (*list)[0];
	free((*list));
	return (tmp);
}
