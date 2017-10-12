/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:31:44 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/26 16:17:53 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t d;

	d = 0;
	len = ft_strlen(src);
	while (dst[d] && d < size)
		d++;
	if (size == d)
		return (len + size);
	size = size - d - 1;
	i = 0;
	while (i < size)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + len);
}
