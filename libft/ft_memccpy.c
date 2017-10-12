/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:31:01 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/02 17:20:45 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*strd;
	const char	*strs;

	strd = dst;
	strs = src;
	while (n > 0)
	{
		if ((*strd++ = *strs++) == c)
			return (void *)(strd);
		n--;
	}
	return (0);
}
