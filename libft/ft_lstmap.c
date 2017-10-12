/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:15:05 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/14 18:35:42 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *res;

	if (!lst || !f)
		return (0);
	if (!(tmp = (t_list *)malloc(sizeof(*tmp))))
		return (0);
	tmp = f(lst);
	res = tmp;
	while (lst->next)
	{
		if (!(tmp->next = malloc(sizeof(*tmp))))
			return (0);
		tmp->next = f(lst->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (res);
}
