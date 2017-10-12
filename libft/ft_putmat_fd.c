/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmat_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:48:11 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 15:56:35 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmat_fd(char **s, int fd)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != NULL)
	{
		ft_putstr_fd(s[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
