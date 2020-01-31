/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:56:35 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/30 12:43:51 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s || start > (unsigned int)ft_strlen(s))
		return (0);
	i = 0;
	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	while (len--)
	{
		str[i] = (char)s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
