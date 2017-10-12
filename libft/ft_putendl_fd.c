/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:46:17 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/13 17:19:36 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		ft_putchar_fd('\n', fd);
	else
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		ft_putchar_fd('\n', fd);
	}
}
