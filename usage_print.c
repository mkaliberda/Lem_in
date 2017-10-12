/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:38:53 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/10 19:38:56 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	random_ants(int name)
{
	if (name % 6 == 1)
		ft_putstr("\x1b[31m");
	if (name % 6 == 2)
		ft_putstr("\x1b[32m");
	if (name % 6 == 3)
		ft_putstr("\x1b[33m");
	if (name % 6 == 4)
		ft_putstr("\x1b[34m");
	if (name % 6 == 5)
		ft_putstr("\x1b[35m");
	if (name % 6 == 6)
		ft_putstr("\x1b[36m");
	if (name % 6 == 7)
		ft_putstr("\x1b[31m");
	if (name % 6 == 8)
		ft_putstr("\x1b[32m");
	if (name % 6 == 9)
		ft_putstr("\x1b[33m");
	if (name % 6 == 0)
		ft_putstr("\x1b[34m");
}

void	random_ants_fin(int name)
{
	if (name % 6 == 1)
		ft_putstr("\x1b[31;5m");
	if (name % 6 == 2)
		ft_putstr("\x1b[32;5m");
	if (name % 6 == 3)
		ft_putstr("\x1b[33;5m");
	if (name % 6 == 4)
		ft_putstr("\x1b[34;5m");
	if (name % 6 == 5)
		ft_putstr("\x1b[35;5m");
	if (name % 6 == 6)
		ft_putstr("\x1b[36;5m");
	if (name % 6 == 7)
		ft_putstr("\x1b[31;5m");
	if (name % 6 == 8)
		ft_putstr("\x1b[32;5m");
	if (name % 6 == 9)
		ft_putstr("\x1b[33;5m");
	if (name % 6 == 0)
		ft_putstr("\x1b[34;5m");
}

void	check_en_col(t_path *room, int name)
{
	if (g_l.rooms[room->index]->index == g_l.end)
		random_ants_fin(name);
	else
		random_ants(name);
}

void	print_res_col(t_path *room, int name)
{
	check_en_col(room, name);
	ft_putstr("L");
	ft_putnbr(name);
	ft_putstr("-");
	ft_putstr(g_l.rooms[room->index]->name);
	ft_putstr("\x1b[0m");
}

void	pint_ant(t_path *room, int name, int *ch)
{
	if (name)
	{
		if (*ch)
			ft_putstr(" ");
		else
			*ch = 1;
	}
	if (g_l.f_c == 0)
		print_res(room, name);
	else
		print_res_col(room, name);
}
