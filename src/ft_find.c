/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:29:54 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_find_i_max_sort(t_stack *s)
{
	int		max;
	int		prev;
	int		new_max;
	int		ind;

	ind = 0;
	prev = s->val;
	new_max = 0;
	max = 0;
	s = s->next;
	while (s)
	{
		if (s->val > prev)
			ft_find_i_max_sort_help2(s, &new_max, &max, &ind);
		else
			new_max = 0;
		prev = s->val;
		s = s->next;
	}
	return (ind);
}

int			ft_find_i_after_sort2(t_stack *s)
{
	int		max;
	int		prev;
	int		new_max;
	int		ind;

	ind = 0;
	prev = s->val;
	new_max = 0;
	max = 0;
	s = s->next;
	while (s)
	{
		if (s->val > prev)
			ft_find_i_after_sort2_help(s, &ind, &new_max, &max);
		else
			new_max = 0;
		prev = s->val;
		s = s->next;
	}
	return (ind + 1);
}

int			ft_find_a_place(t_stacks *s)
{
	int		prev;
	t_stack	*a_temp;

	a_temp = s->a;
	prev = a_temp->val;
	a_temp = a_temp->next;
	while (a_temp)
	{
		if (a_temp->val < prev && s->tmp_b->val < a_temp->val)
			return (a_temp->i);
		if (a_temp->val < prev && s->tmp_b->val > prev)
			return (a_temp->i);
		if (s->tmp_b->val > prev && s->tmp_b->val < a_temp->val)
			return (a_temp->i);
		prev = a_temp->val;
		if (a_temp->next == NULL && s->tmp_b->val > a_temp->val)
			return (ft_get_slen(s->a));
		a_temp = a_temp->next;
	}
	return (0);
}

int			ft_find_comb(t_stacks *s, int a_ind)
{
	if (s->tmp_b->i <= s->len_b / 2 && a_ind <= s->len_a / 2)
		return (1);
	if (s->tmp_b->i > s->len_b / 2 && a_ind > s->len_a / 2)
		return (2);
	if (s->tmp_b->i > s->len_b / 2 && a_ind <= s->len_a / 2)
		return (3);
	if (s->tmp_b->i <= s->len_b / 2 && a_ind > s->len_a / 2)
		return (4);
	return (0);
}

int			ft_find_comb_bigger5(t_stacks *s, int a_ind)
{
	if (s->tmp_b->i < s->len_b / 2 && a_ind < s->len_a / 2)
		return (1);
	if (s->tmp_b->i >= s->len_b / 2 && a_ind >= s->len_a / 2)
		return (2);
	if (s->tmp_b->i >= s->len_b / 2 && a_ind < s->len_a / 2)
		return (3);
	if (s->tmp_b->i < s->len_b / 2 && a_ind >= s->len_a / 2)
		return (4);
	return (0);
}
