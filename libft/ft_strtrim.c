/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:40:35 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 15:25:27 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			n;
	size_t			p;

	if (!s)
		return (0);
	i = 0;
	p = 0;
	n = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	if (i == n)
		return (ft_strsub("", 0, 0));
	while (s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t')
		n--;
	p = n - i;
	str = ft_strsub(s, i, p);
	return (str);
}
