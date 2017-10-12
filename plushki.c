/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plushki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:20:22 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/03 16:20:24 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_count(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	add_map(void)
{
	g_l.map = ft_strjoinf(g_l.map, g_l.str_temp);
	g_l.map = ft_strjoinf(g_l.map, "\n");
}

int		count_split(char **str)
{
	int res;
	int j;

	res = 0;
	j = -1;
	while (str[++j])
		res++;
	return (res);
}

void	free_array_char(char **str)
{
	int j;

	j = -1;
	while (str[++j])
		free(str[j]);
	free(str);
}

void	ft_init_matrix(void)
{
	int	i;
	int j;

	j = 0;
	g_l.matrix = (int**)malloc(sizeof(int*) * g_l.count_room);
	while (j < g_l.count_room)
	{
		i = 0;
		g_l.matrix[j] = (int*)malloc(sizeof(int) * g_l.count_room);
		while (i < g_l.count_room)
		{
			g_l.matrix[j][i] = 0;
			i++;
		}
		j++;
	}
}
