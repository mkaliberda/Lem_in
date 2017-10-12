/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:46:35 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/13 17:44:37 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd(nb % 10 + '0', fd);
}
