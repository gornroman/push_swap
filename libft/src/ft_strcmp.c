/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:14:16 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/16 11:22:36 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
		i++;
	return (a[i] - b[i]);
}
