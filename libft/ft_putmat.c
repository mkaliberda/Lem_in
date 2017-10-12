/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:35:00 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 15:56:19 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmat(char **s)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != NULL)
	{
		ft_putstr(s[i]);
		ft_putchar('\n');
		i++;
	}
}