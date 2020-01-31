/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:11:49 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/30 12:44:21 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(const char *s1, const char *s2)
{
	char	*a;
	char	*b;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	while (a[i])
	{
		if (a[i] == b[i])
		{
			i++;
		}
		else
			return (0);
	}
	if (i == (size_t)ft_strlen(s2))
		return (1);
	return (0);
}
