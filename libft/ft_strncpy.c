/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:59:09 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/26 16:30:03 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	res = dst;
	while (len > 0 && src[i])
	{
		res[i] = src[i];
		i++;
		len--;
	}
	while (len > 0)
	{
		res[i] = '\0';
		i++;
		len--;
	}
	return (res);
}
