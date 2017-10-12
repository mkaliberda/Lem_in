/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:39:57 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/03 15:39:59 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *error)
{
	if (g_l.f_u == 1)
	{
		ft_putstr("\x1b[33m");
		ft_putstr("HI! WHY DO YOU TRY CRASH ME? \n");
		ft_putstr("\x1b[0m");
		ft_putstr("\x1b[31m");
		ft_putstr("MAP HAS ERROR: \n");
		ft_putstr("\x1b[0m");
		ft_putstr(error);
		ft_putstr("\nIt must be line: ");
		ft_putstr("\x1b[31m");
		ft_putstr(g_l.str_temp);
		ft_putstr("\x1b[0m");
		ft_putstr("\n");
	}
	else
		ft_putstr("ERROR\n");
	exit(-1);
}

void	ft_check_ants(void)
{
	if (g_l.str_temp[0] == '#')
		add_map();
	else
	{
		add_map();
		g_l.count_ants = ft_atoi(g_l.str_temp);
		if (!(ft_check_count(g_l.str_temp)
			&& ft_strlen(g_l.str_temp) <= 10) || g_l.count_ants < 1)
			ft_error("I CANT USE THIS ANTS. ANTS MUST BE INT AND POSITIVE");
		else
			g_l.res = 1;
	}
	free(g_l.str_temp);
}

void	ft_validator(void)
{
	while (g_l.res == 0 && get_next_line(0, &g_l.str_temp))
	{
		ft_check_ants();
	}
	while (g_l.res && (get_next_line(0, &g_l.str_temp)))
	{
		if (ft_strlen(g_l.str_temp) == 0)
			ft_error("I CANT USE EMPTY ROOM");
		check_room();
		free(g_l.str_temp);
	}
	while (get_next_line(0, &g_l.str_temp))
	{
		if (ft_strlen(g_l.str_temp) == 0)
			ft_error("I CANT USE EMPTY CONNECT");
		parse_connect();
		free(g_l.str_temp);
	}
	if (g_l.count_room == 0)
		ft_error("I CANT USE MAP WITHOUT ANT OR ROOMS OR CONNECTION");
}

int		ft_generate_var(void)
{
	g_l.res = 0;
	g_l.start = -1;
	g_l.end = -1;
	g_l.count_ants = 0;
	g_l.count_room = 0;
	g_l.count_path = 0;
	g_l.rooms = NULL;
	g_l.path = NULL;
	g_l.map = ft_strnew(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_path		*tmp_path;
	t_path		*min_p;

	tmp_path = NULL;
	check_usage(ac, av);
	ft_generate_var();
	ft_validator();
	if (g_l.count_ants == 0)
		ft_error("I CANT USE MAP WITHOUT ANT OR ROOMS OR CONNECTION");
	validate_connect();
	g_l.rooms[g_l.start]->check = START;
	g_l.rooms[g_l.end]->check = END;
	ft_addlist_path(&tmp_path, g_l.rooms[g_l.start]->index);
	find_path(&tmp_path, g_l.rooms[g_l.start]->index);
	min_p = min_path();
	ft_putstr(g_l.map);
	if (g_l.f_p == 1)
		print_all_path();
	output(min_p->next);
	return (0);
}
