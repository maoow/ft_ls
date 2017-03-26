/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:53:11 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/11 16:18:52 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	int		i;
	t_list	*new;

	i = 0;
	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content && content_size)
	{
		if ((new->content = malloc(content_size * sizeof(void))) == NULL)
			return (NULL);
		new->content_size = content_size;
		new->content = ft_memcpy(new->content, content, content_size);
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
