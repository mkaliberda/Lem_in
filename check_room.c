/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:41:10 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/03 17:41:12 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char **str)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(str[0]);
	room->x = ft_atoi(str[1]);
	room->y = ft_atoi(str[2]);
	if (room->x < 0 || room->y < 0
		|| !ft_check_count(str[1]) || !ft_check_count(str[2]))
		ft_error("MUST BE VALID ROOMS");
	room->index = g_l.count_room;
	room->check = 0;
	return (room);
}

void	add_room(t_room *new_room)
{
	t_room	**tmp;
	int		i;

	i = 0;
	tmp = (t_room**)malloc(sizeof(t_room*) * g_l.count_room + 1);
	while (i != g_l.count_room)
	{
		if (!ft_strcmp(new_room->name, g_l.rooms[i]->name))
			ft_error("I CANT USE 2 ROOM WITH SIMILAR NAME");
		tmp[i] = g_l.rooms[i];
		i++;
	}
	tmp[i] = new_room;
	free(g_l.rooms);
	g_l.rooms = tmp;
	g_l.count_room++;
}

int		ft_pars_room(void)
{
	char **tmp_spl;

	tmp_spl = ft_strsplit(g_l.str_temp, ' ');
	if (count_split(tmp_spl) != 3)
		ft_error("ROOM MUST HAVE ONLY 3 ARGUMENTS");
	add_room(new_room(tmp_spl));
	free_array_char(tmp_spl);
	return (ROOM);
}

int		if_sharp(void)
{
	char	*tmp;

	if (g_l.str_temp[0] == '#')
	{
		if (!ft_strcmp(g_l.str_temp, "##start"))
			g_l.start != -1 ? ft_error("I CANT USE FEW START.")
		: (g_l.start = g_l.count_room);
		else if (!ft_strcmp(g_l.str_temp, "##end"))
			g_l.end != -1 ? ft_error("I CANT USE FEW END.")
		: (g_l.end = g_l.count_room);
		return (COMMENT);
	}
	else if ((tmp = ft_strchr(g_l.str_temp, ' ')) && (ft_strchr(tmp + 1, ' ')))
	{
		tmp = ft_strchr(tmp + 1, ' ');
		if (ft_strchr(tmp + 1, ' '))
			ft_error("I CANT USE THIS MAP. IT MUST HAVE 3 ARGUMENTS IN ROOM");
		return (ft_pars_room());
	}
	else if (ft_strchr(g_l.str_temp, ' '))
		ft_error("I CANT USE THIS MAP. IT MUST HAVE 3 ARGUMENTS ROOM");
	return (CONNECT);
}

void	check_room(void)
{
	add_map();
	if (if_sharp() == CONNECT)
	{
		g_l.res = 0;
		ft_init_matrix();
		if (g_l.count_room == 0)
			ft_error("I CANT USE MAP WITHOUT ROOMS");
		if (g_l.start == g_l.end)
			ft_error("I CANT START == END");
		if (g_l.end == g_l.count_room || g_l.end == -1)
			ft_error("I CANT find end");
		if (g_l.start == g_l.count_room || g_l.start == -1)
			ft_error("I CANT find start");
		parse_connect();
	}
}
