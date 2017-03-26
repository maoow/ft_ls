/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:23:36 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/11 16:18:52 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputstr(t_list **list)
{
	t_list *next;

	next = *list;
	while (next != NULL)
	{
		ft_putstr(next->content);
		next = next->next;
	}
}
