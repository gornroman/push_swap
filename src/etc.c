/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:27:19 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_len_of_int(int nbr)
{
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int			ft_is_not_dub(t_stack *s, int value)
{
	while (s)
	{
		if (s->val == value)
			return (0);
		s = s->next;
	}
	return (1);
}

void		ft_put_error(t_stacks **s)
{
	ft_putstr("Error\n");
	ft_stacks_free(s);
	exit(1);
}

void		ft_free_array(char **array)
{
	int		i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array && *array)
		free(array);
}

int			ft_check_int(int val_i, char *val_c)
{
	char	*val;
	int		res;

	res = 0;
	val = ft_itoa(val_i);
	if (ft_strcmp(val, val_c) == 0)
		res = 1;
	if (val)
		free(val);
	return (res);
}
