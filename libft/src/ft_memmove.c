/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:35:06 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/24 17:20:47 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (s == d)
		return (dst);
	if (d <= s || d >= (s + len))
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
