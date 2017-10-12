/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:03:25 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/10 15:03:26 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_size(t_path *tmp)
{
	int		res;

	res = 0;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

void	print_res(t_path *room, int name)
{
	ft_putstr("L");
	ft_putnbr(name);
	ft_putstr("-");
	ft_putstr(g_l.rooms[room->index]->name);
}

void	ft_error_flag(void)
{
	ft_putstr("\x1b[33m");
	ft_putstr("HI ARTIST! \nYOU CAN USE FLAGS: \n");
	ft_putstr("\x1b[0m");
	ft_putstr("\x1b[92m");
	ft_putstr("-u .... turn on usage error\n");
	ft_putstr("-c .... turn on colors in output way\n");
	ft_putstr("-p .... output all path\n");
	ft_putstr("--help  display instruction\n");
	ft_putstr("\x1b[0m");
	exit(-1);
}

void	print_all_path(void)
{
	t_list	*tmp;
	t_path	*tmp_p;

	tmp = g_l.path;
	ft_putstr("\n");
	ft_putstr("All path");
	ft_putstr("\n");
	while (tmp)
	{
		tmp_p = tmp->content;
		while (tmp_p)
		{
			ft_putstr(g_l.rooms[tmp_p->index]->name);
			ft_putstr(" ");
			tmp_p = tmp_p->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	check_usage(int ac, char **av)
{
	int i;

	i = 1;
	g_l.f_u = 0;
	g_l.f_c = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-u") && ft_strcmp(av[i], "-c")
			&& ft_strcmp(av[i], "--help") && ft_strcmp(av[i], "-p"))
			ft_error_flag();
		if (!ft_strcmp(av[i], "--help"))
			ft_error_flag();
		if (!ft_strcmp(av[i], "-u"))
			g_l.f_u = 1;
		if (!ft_strcmp(av[i], "-c"))
			g_l.f_c = 1;
		if (!ft_strcmp(av[i], "-p"))
			g_l.f_p = 1;
		i++;
	}
}
