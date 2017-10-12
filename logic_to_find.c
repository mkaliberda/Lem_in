/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_to_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:30:19 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/09 14:30:21 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_addlist_path(t_path **lst, int index)
{
	t_path	*tmp;
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	new->index = index;
	new->next = NULL;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	ft_lstdelback(t_path **list)
{
	t_path	*tmp;

	tmp = *list;
	if (!tmp->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void	ft_lstaddback(t_list **lst, void *elm, int size)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = elm;
	new->content_size = (size_t)size;
	new->next = NULL;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int		ft_add_path_to_main(t_path **tmp_path, int index)
{
	t_path *tmp;

	ft_addlist_path(tmp_path, index);
	tmp = *tmp_path;
	ft_lstaddback(&g_l.path, (void*)(*tmp_path), path_size(*tmp_path));
	*tmp_path = NULL;
	while (tmp)
	{
		ft_addlist_path(tmp_path, tmp->index);
		tmp = tmp->next;
	}
	ft_lstdelback(tmp_path);
	return (0);
}

int		find_path(t_path **tmp_path, int curr)
{
	int		index;

	index = -1;
	while (++index < g_l.count_room)
	{
		if (g_l.rooms[index]->check == END && g_l.matrix[index][curr])
		{
			(ft_add_path_to_main(tmp_path, index));
			continue ;
		}
		if (!g_l.rooms[index]->check && g_l.matrix[index][curr])
		{
			ft_addlist_path(tmp_path, index);
			g_l.rooms[index]->check = 1;
			find_path(tmp_path, index);
			ft_lstdelback(tmp_path);
			g_l.rooms[index]->check = 0;
		}
	}
	return (0);
}
