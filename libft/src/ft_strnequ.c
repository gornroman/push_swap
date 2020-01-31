/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:35:34 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/23 15:32:54 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return ((int)NULL);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
