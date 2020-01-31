/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:16:47 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/18 18:41:07 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0')
		i++;
	x = 0;
	while (src[x] != '\0')
		x++;
	if (size <= i)
		x = x + size;
	else
		x = x + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (x);
}
