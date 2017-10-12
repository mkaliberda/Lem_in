/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:48:02 by mkaliber          #+#    #+#             */
/*   Updated: 2016/12/13 17:22:10 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	str = (char *)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
