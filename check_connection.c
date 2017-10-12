/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:36:26 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/04 14:36:28 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_chek_first_connect(int ind)
{
	int i;

	i = -1;
	while (g_l.rooms[ind]->name[++i] && i < ft_strlen(g_l.rooms[ind]->name))
		if (g_l.rooms[ind]->name[i] != g_l.str_temp[i])
			return (NULL);
	if (g_l.str_temp[i] == '-')
		return (g_l.str_temp + i + 1);
	return (NULL);
}

void	validator_connect(void)
{
	int		i;
	char	*str;

	i = -1;
	while (++i < g_l.count_room)
	{
		if ((str = ft_chek_first_connect(i)))
		{
			g_l.gx = i;
			break ;
		}
	}
	if (!str)
		ft_error("I CANT USE SOME CONNECT. IT NOT VALID");
	i = -1;
	while (++i < g_l.count_room)
	{
		if (!ft_strcmp(str, g_l.rooms[i]->name))
		{
			g_l.gy = i;
			return ;
		}
	}
	ft_error("I CANT USE SOME CONNECTS. PLEASE CHECK IT");
}

void	parse_connect(void)
{
	g_l.gx = 0;
	g_l.gy = 0;
	add_map();
	if (g_l.str_temp[0] != '#')
	{
		validator_connect();
		if (g_l.gx == -1 || g_l.gy == -1 || g_l.gx == g_l.gy)
			ft_error("I CANT USE SOME CONNECTS. PLEASE CHECK IT");
		g_l.matrix[g_l.gx][g_l.gy] = 1;
		g_l.matrix[g_l.gy][g_l.gx] = 1;
	}
}
