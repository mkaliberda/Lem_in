/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:55:02 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/06 17:55:04 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	validate_connect(void)
{
	int	check;

	g_l.gy = 0;
	if (!g_l.matrix)
		ft_error("NO PATH");
	while (g_l.gy < g_l.count_room)
	{
		g_l.gx = 0;
		check = 0;
		while (g_l.gx < g_l.count_room)
		{
			if (g_l.matrix[g_l.gx][g_l.gy] == 1)
				check = 1;
			g_l.gx++;
		}
		if (check != 1)
			ft_error("NO CONNECT PATH");
		check = 0;
		g_l.gy++;
	}
}
