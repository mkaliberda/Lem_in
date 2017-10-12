/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:45:55 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/09 18:40:28 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1);
	i = 0;
	if (!(str = (char *)malloc((ft_strlen(s1) +
						ft_strlen(s2) + 1) * sizeof(*str))))
		return (0);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	while (s2[i] != '\0')
	{
		str[n] = s2[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
