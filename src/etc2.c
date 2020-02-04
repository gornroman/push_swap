/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 16:36:29 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_start_swaping(t_stacks *s)
{
	int		min_steps;
	int		i;

	s->tmp_b = s->b;
	s->len_a = ft_get_slen(s->a);
	s->len_b = ft_get_slen(s->b);
	min_steps = 100000;
	ft_index(s->a);
	ft_index(s->b);
	while (s->tmp_b)
	{
		i = ft_swap(s);
		if (i < min_steps)
		{
			min_steps = i;
			s->ind_b = s->tmp_ind_b;
			s->ind_a = s->tmp_ind_a;
			s->comb = s->tmp_comb;
		}
		s->tmp_b = s->tmp_b->next;
	}
	ft_move_to_a(s);
}

int			ft_find_turn(t_stacks *s)
{
	int		prev;
	t_stack	*temp;

	temp = s->a;
	prev = temp->val;
	temp = temp->next;
	while (temp)
	{
		if (prev > temp->val)
			return (temp->i);
		prev = temp->val;
		temp = temp->next;
	}
	return (0);
}

void		ft_check_last(t_stacks *s)
{
	int		last_elem;

	if (ft_check_sort(s->a) == 0)
		return ;
	last_elem = ft_last_elem(s->a);
	while (s->a->val > last_elem)
	{
		ft_do_cmd_0("rra", 1, s);
		last_elem = ft_last_elem(s->a);
	}
}

int			ft_get_slen(t_stack *s)
{
	int count;

	count = 0;
	while (s)
	{
		s = s->next;
		count++;
	}
	return (count);
}

int			ft_same_sort_in_end(t_stack *a, int i)
{
	t_stack	*temp;
	int		move;
	int		prev;

	temp = a;
	move = ft_get_slen(a) - i;
	while (move)
	{
		temp = temp->next;
		move--;
	}
	prev = temp->val;
	temp = temp->next;
	while (temp)
	{
		if (prev > temp->val)
			return (0);
		prev = temp->val;
		temp = temp->next;
	}
	return (1);
}
