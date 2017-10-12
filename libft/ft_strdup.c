/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:19:09 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/26 16:16:41 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*dst))))
		return (NULL);
	dst = ft_strcpy(dst, s1);
	return (dst);
}
