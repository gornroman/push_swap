/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:54:23 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/13 12:41:16 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	x;

	x = ft_strlen((char*)s);
	while (x && s[x] != (char)c)
		x--;
	if (s[x] == (char)c)
		return ((char*)&s[x]);
	return (NULL);
}
