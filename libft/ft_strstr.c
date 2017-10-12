/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:17:11 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/08 17:30:02 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *b;
	char *l;
	char *r;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		r = (char *)big;
		l = (char *)little;
		b = (char *)big;
		while (*b == *l && *b != '\0' && *l != '\0')
		{
			b++;
			l++;
		}
		if (*l == '\0')
			return ((char *)r);
		big++;
	}
	return (0);
}
