/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:10 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 15:36:04 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char sb;

	str = (unsigned char *)s;
	sb = (unsigned char)c;
	while (n > 0)
	{
		if (*str == sb)
			return ((void *)str);
		n--;
		str++;
	}
	return (0);
}
