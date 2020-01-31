/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:47:28 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/12 18:12:35 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*a;
	const char	*b;
	int			i;

	i = 0;
	a = s1;
	b = s2;
	while (n--)
	{
		if (a[i] == b[i])
		{
			i++;
		}
		else
			return ((unsigned char)a[i] - (unsigned char)b[i]);
	}
	return (0);
}
