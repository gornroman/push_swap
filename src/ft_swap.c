/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:32:19 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_swap(t_stacks *s)
{
	int		min_route;
	int		a_ind;
	int		comb;

	a_ind = ft_find_a_place(s);
	if (s->firstlen > 5)
		comb = ft_find_comb_bigger5(s, a_ind);
	else
		comb = ft_find_comb(s, a_ind);
	min_route = ft_find_route(s, comb, a_ind);
	s->tmp_comb = comb;
	s->tmp_ind_a = a_ind;
	s->tmp_ind_b = s->tmp_b->i;
	return (min_route);
}
