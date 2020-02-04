/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:02:43 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_find_i_max_sort_help2(t_stack *s, int *new_max,
		int *max, int *ind)
{
	(*new_max)++;
	if (*new_max > *max)
	{
		*max = *new_max;
		*ind = s->i - (*max);
	}
}

void		ft_find_i_after_sort2_help(t_stack *s, int *ind,
		int *new_max, int *max)
{
	(*new_max)++;
	if (*new_max > *max)
	{
		*max = *new_max;
		*ind = s->i;
	}
}

void		ft_move_unsort_3_help(t_stacks *s, int i)
{
	if (ft_same_sort_in_end(s->a, ft_find_i_after_sort2(s->a)) == 0)
		ft_do_cmd_0("ra", ft_get_slen(s->a) - i, s);
	while (i)
	{
		if (s->a->val < ft_last_elem(s->a))
			ft_do_cmd_0("pb", 1, s);
		else
			ft_do_cmd_0("ra", 1, s);
		if (ft_check_sort(s->a) == 1)
			return ;
		i--;
	}
}

void		ft_do_route1_help(int *min, int *max, char **cmd, t_stacks *s)
{
	if (s->ind_b < s->ind_a)
	{
		*min = s->ind_b;
		*max = s->ind_a;
		*cmd = ft_strcpy(*cmd, "ra");
	}
	else
	{
		*min = s->ind_a;
		*max = s->ind_b;
		*cmd = ft_strcpy(*cmd, "rb");
	}
}

void		ft_do_route2_help(int *len_min_m, int *len_max_m,
		char **cmd, t_stacks *s)
{
	if (s->len_b - s->ind_b < s->len_a - s->ind_a)
	{
		*len_max_m = s->len_b - s->ind_b;
		*len_min_m = s->len_a - s->ind_a;
		*cmd = ft_strcpy(*cmd, "rra");
	}
	else
	{
		*len_max_m = s->len_a - s->ind_a;
		*len_min_m = s->len_b - s->ind_b;
		*cmd = ft_strcpy(*cmd, "rrb");
	}
}
