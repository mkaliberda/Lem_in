/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:10:47 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/23 18:59:16 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*anton(char *str, long int n, size_t len)
{
	size_t i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = 1;
	}
	while (len > i)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		if (n > 9)
			n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long int	nb;

	nb = n;
	len = ft_len(nb);
	if (!(str = (char *)malloc((len + 1) * sizeof(*str))))
		return (NULL);
	str[len] = '\0';
	return (anton(str, nb, len));
}
