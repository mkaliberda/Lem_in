/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:02:48 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/11 11:02:50 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	go_ant(t_path *room, int name, int *ch)
{
	if (room->next)
		go_ant(room->next, g_l.rooms[room->index]->check, ch);
	g_l.rooms[room->index]->check = name;
	if (name)
		pint_ant(room, name, ch);
}

void	output(t_path *room)
{
	int	i;
	int	ch;
	int	ant;

	i = -1;
	ant = -1;
	while (++i < g_l.count_room)
		g_l.rooms[i]->check = 0;
	while (g_l.rooms[g_l.end]->check != g_l.count_ants)
	{
		ch = 0;
		go_ant(room, (++ant > g_l.count_ants ? 0 : ant), &ch);
		ft_putstr("\n");
	}
}

t_path	*min_path(void)
{
	t_path	*min;
	t_list	*tmp;
	int		i_min;

	min = (t_path*)g_l.path->content;
	tmp = g_l.path;
	i_min = (int)g_l.path->content_size;
	while (tmp)
	{
		if (i_min > tmp->content_size)
		{
			i_min = (int)tmp->content_size;
			min = (t_path*)tmp->content;
		}
		tmp = tmp->next;
	}
	return (min);
}
