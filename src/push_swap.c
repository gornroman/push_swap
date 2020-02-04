/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 18:23:41 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_move_unsort_3(t_stacks *s)
{
	int		i;

	if (ft_is_sorted_1(s->a))
		return ;
	if (ft_find_i_after_sort2(s->a) < 3)
		i = ft_get_slen(s->a) - 3;
	else
		i = ft_get_slen(s->a) - ft_find_i_after_sort2(s->a);
	if (ft_find_i_after_sort2(s->a) >= 3)
		ft_move_unsort_3_help(s, i);
	else
	{
		if (ft_check_unsort(s) == 0)
			ft_do_cmd_0("ra", i, s);
		ft_do_cmd_0("pb", i, s);
	}
}

void		ft_sort_3(t_stacks *s)
{
	if (s->a->val > s->a->next->val)
	{
		if (s->a->val < s->a->next->next->val)
			ft_do_cmd_0("sa", 1, s);
		else if (s->a->next->next->val > s->a->next->val)
			ft_do_cmd_0("ra", 1, s);
		else
		{
			ft_do_cmd_0("sa", 1, s);
			ft_do_cmd_0("rra", 1, s);
		}
	}
	else
	{
		if (s->a->val < s->a->next->next->val)
		{
			ft_do_cmd_0("sa", 1, s);
			ft_do_cmd_0("ra", 1, s);
		}
		else
			ft_do_cmd_0("rra", 1, s);
	}
}

int			ft_is_sorted_1(t_stack *s)
{
	t_stack	*tmp;
	int		last_value;

	tmp = s;
	last_value = tmp->val;
	while (tmp)
	{
		if (last_value > tmp->val)
			return (0);
		last_value = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}

void		ft_start_pushing(t_stacks *s)
{
	if (ft_get_slen(s->a) == 2 && ft_is_sorted_1(s->a) == 0)
		ft_do_cmd_0("sa", 1, s);
	else if (ft_get_slen(s->a) == 3 && ft_is_sorted_1(s->a) == 0)
		ft_sort_3(s);
	else if (ft_is_sorted_1(s->a) == 0)
	{
		ft_move_unsort(s);
		ft_check_last(s);
		ft_index(s->a);
		s->sort_from_start == 1 ? ft_move_unsort_3(s) : ft_move_unsort(s);
		if (ft_is_sorted_1(s->a) == 0 && ft_get_slen(s->a) == 3)
			ft_sort_3(s);
	}
	while (ft_get_slen(s->b) > 0)
		ft_start_swaping(s);
	ft_index(s->a);
	while (ft_is_sorted(s) == 0)
	{
		if (ft_find_turn(s) > ft_get_slen(s->a) / 2)
			ft_do_cmd_0("rra", 1, s);
		else
			ft_do_cmd_0("ra", 1, s);
	}
}

int			main(int argc, char **argv)
{
	t_stacks	*s;

	s = ft_create_stack(argc, argv);
	s->flag_print = 1;
	ft_start_pushing(s);
	ft_stacks_free(&s);
	return (1);
}
