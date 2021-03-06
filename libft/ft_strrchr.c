/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:18:01 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 16:03:19 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	s = s + n;
	while (n >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		n--;
	}
	return (0);
}
