/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:56:01 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/15 16:59:32 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (new_lst == NULL)
		return (0);
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = ft_memalloc(content_size)))
			return (0);
		new_lst->content = ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	return (new_lst);
}
