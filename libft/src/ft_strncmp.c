/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:17:23 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/18 12:00:30 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && n--)
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
