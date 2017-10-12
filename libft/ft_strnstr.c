/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:09:45 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/19 17:31:07 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	char	*r;
	size_t	n;

	if (!*little)
		return ((char *)big);
	while (*big != '\0' && len)
	{
		n = len;
		r = (char *)big;
		l = (char *)little;
		b = (char *)big;
		while (*b == *l && *b != '\0' && *l != '\0' && n)
		{
			b++;
			l++;
			n--;
		}
		if (*l == '\0')
			return ((char *)r);
		big++;
		len--;
	}
	return (0);
}
