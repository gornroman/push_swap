/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:30:25 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/18 17:02:25 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lastc(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (s[i] && i)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		else
			return (i);
	}
	return (i);
}

static int	ft_firstc(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			return (i);
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_lastc(s);
	j = 0;
	i = ft_firstc(s);
	if (n <= i)
		str = (char*)malloc(1);
	else
		str = (char*)malloc(n - i + 2);
	if (!str)
		return (NULL);
	while (i <= n)
	{
		str[j] = (char)s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
