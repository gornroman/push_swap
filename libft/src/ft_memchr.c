/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:27:30 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/12 18:09:56 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (n--)
	{
		if (a[i] == (char)c)
			return (void*)(a + i);
		i++;
	}
	return (NULL);
}
