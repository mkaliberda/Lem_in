/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:20:16 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/02 17:28:31 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*strd;
	unsigned const char		*strs;
	size_t					tln;

	strd = (unsigned char *)dst;
	strs = (unsigned char *)src;
	if (strs > strd)
	{
		tln = 0;
		while (tln != len)
		{
			strd[tln] = strs[tln];
			tln++;
		}
	}
	else
	{
		tln = len;
		while (tln > 0)
		{
			strd[tln - 1] = strs[tln - 1];
			tln--;
		}
	}
	return (void *)(dst);
}
