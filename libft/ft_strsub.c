/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:25:02 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/13 17:50:35 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!s)
		return (0);
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	while (s[start] != '\0' && len != n)
	{
		str[n] = s[start];
		start++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
