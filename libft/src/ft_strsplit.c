/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:37:15 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/23 11:39:17 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_qofwords(char const *str, char c)
{
	int counter;
	int i;

	i = 0;
	counter = 0;
	if (str[i] != c)
		counter++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static char	*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	k = 0;
	s = (char*)malloc(sizeof(s) * ft_strlen(str));
	if (!s)
		return (NULL);
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		(*i)++;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		(*i)++;
	return (s);
}

static int	ft_skip_c(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c && str[i])
		i++;
	return (i);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		w;
	char	**s;

	if (!str || !c)
		return (NULL);
	j = 0;
	w = ft_qofwords(str, c);
	s = (char**)malloc(sizeof(s) * (ft_qofwords(str, c) + 2));
	if (!s)
		return (NULL);
	i = ft_skip_c(str, c);
	while (j < w && str[i])
	{
		s[j] = ft_word(str, c, &i);
		if (!s[j])
		{
			ft_free(s, i);
			return (NULL);
		}
		j++;
	}
	s[j] = NULL;
	return (s);
}
