/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_route.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:33:50 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_do_route1(t_stacks *s)
{
	int		min;
	int		max;
	char	*cmd;

	cmd = ft_strnew(3);
	ft_do_route1_help(&min, &max, &cmd, s);
	if (s->ind_b == 0)
	{
		ft_do_cmd_0("ra", s->ind_a, s);
		ft_do_cmd_0("pa", 1, s);
	}
	else
	{
		ft_do_cmd_0("rr", min, s);
		ft_do_cmd_0(cmd, (max - min), s);
		ft_do_cmd_0("pa", 1, s);
	}
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
	free(cmd);
}

void		ft_do_route2(t_stacks *s)
{
	char	*cmd;
	int		len_min_m;
	int		len_max_m;

	cmd = ft_strnew(4);
	ft_do_route2_help(&len_min_m, &len_max_m, &cmd, s);
	ft_do_cmd_0("rrr", len_max_m, s);
	if (s->len_a == s->ind_a && s->ind_b == 0)
		ft_do_cmd_0("pa", 1, s);
	else
	{
		ft_do_cmd_0(cmd, (len_min_m - len_max_m), s);
		ft_do_cmd_0("pa", 1, s);
	}
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
	free(cmd);
}

void		ft_do_route3(t_stacks *s)
{
	ft_do_cmd_0("ra", s->ind_a, s);
	if (s->len_b > 1)
		ft_do_cmd_0("rrb", (s->len_b - s->ind_b), s);
	ft_do_cmd_0("pa", 1, s);
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
}

void		ft_do_route4(t_stacks *s)
{
	ft_do_cmd_0("rra", (s->len_a - s->ind_a), s);
	ft_do_cmd_0("rb", s->ind_b, s);
	ft_do_cmd_0("pa", 1, s);
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
}

void		ft_move_to_a(t_stacks *s)
{
	if (s->comb == 1)
		ft_do_route1(s);
	else if (s->comb == 2)
		ft_do_route2(s);
	else if (s->comb == 3)
		ft_do_route3(s);
	else if (s->comb == 4)
		ft_do_route4(s);
}
