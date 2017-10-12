/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:09:31 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/22 16:06:29 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	bust(char *str, char c, size_t i)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

static size_t	bust_nc(char *str, char c, size_t i)
{
	size_t l;
	size_t n;

	n = i;
	l = 0;
	while (str[n] != c && str[n] != '\0')
	{
		n++;
		l++;
	}
	return (l);
}

static size_t	count_words(char *str, char c)
{
	size_t i;
	size_t count;
	size_t s;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		s = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			s++;
			i++;
		}
		if (s > 0)
			count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	rows;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	rows = count_words((char *)s, c);
	len = 0;
	i = 0;
	if (!(str = (char **)malloc((rows + 1) * sizeof(*str))))
		return (NULL);
	str[rows] = NULL;
	rows = 0;
	while (rows != count_words((char *)s, c))
	{
		i = bust((char *)s, c, i);
		len = bust_nc((char *)s, c, i);
		str[rows] = ft_strsub(s, i, len);
		i = i + len;
		rows++;
	}
	return (str);
}
