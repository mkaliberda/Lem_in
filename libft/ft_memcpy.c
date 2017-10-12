/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:37:45 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/02 17:02:24 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*strd;
	unsigned const char	*strs;

	strs = src;
	strd = dst;
	while (n > 0)
	{
		*strd = *strs;
		strd++;
		strs++;
		n--;
	}
	return (dst);
}
