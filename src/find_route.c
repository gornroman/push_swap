/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:28:28 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_route1(t_stacks *s, int a_ind)
{
	int		way;
	int		min;
	int		max;

	if (s->tmp_b->i < a_ind)
	{
		min = s->tmp_b->i;
		max = a_ind;
	}
	else
	{
		min = a_ind;
		max = s->tmp_b->i;
	}
	way = min + (max - min) + 1;
	return (way);
}

int			ft_find_route2(t_stacks *s, int a_ind)
{
	int		way;
	int		min;
	int		max;
	int		len_min;
	int		len_max;

	if (s->len_b - s->tmp_b->i < s->len_a - a_ind)
	{
		min = s->tmp_b->i;
		len_min = s->len_b;
		max = a_ind;
		len_max = s->len_a;
	}
	else
	{
		min = a_ind;
		len_min = s->len_a;
		max = s->tmp_b->i;
		len_max = s->len_b;
	}
	way = (len_min - min);
	way = way + ((len_max - max) - (len_min - min)) + 1;
	return (way);
}

int			ft_find_route3(t_stacks *s, int a_ind)
{
	int		way;

	way = a_ind + (s->len_b - s->tmp_b->i) + 1;
	return (way);
}

int			ft_find_route4(t_stacks *s, int a_ind)
{
	int		way;

	way = (s->len_a - a_ind) + s->tmp_b->i + 1;
	return (way);
}

int			ft_find_route(t_stacks *s, int comb, int a_ind)
{
	int		result;

	result = 0;
	if (comb == 1)
		result = ft_find_route1(s, a_ind);
	else if (comb == 2)
		result = ft_find_route2(s, a_ind);
	else if (comb == 3)
		result = ft_find_route3(s, a_ind);
	else if (comb == 4)
		result = ft_find_route4(s, a_ind);
	return (result);
}
