/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:10:51 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/12 21:05:55 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *tmp;

	if (!lst)
		return (NULL);
	newlist = (*f)(lst);
	lst = lst->next;
	tmp = newlist;
	while (lst)
	{
		tmp->next = (*f)(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (newlist);
}
