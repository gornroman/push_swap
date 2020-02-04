/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 16:36:29 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_last_elem(t_stack *a)
{
	while (a && a->next)
		a = a->next;
	return (a ? a->val : 0);
}

void		ft_index(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		s->i = i;
		s = s->next;
		i++;
	}
}

void		ft_move_unsort(t_stacks *s)
{
	int	i_max_sort;

	ft_index(s->a);
	if (ft_get_slen(s->a) - ft_find_i_max_sort(s->a) >= 3)
		i_max_sort = ft_find_i_max_sort(s->a);
	else
		i_max_sort = ft_get_slen(s->a) - 3;
	if (i_max_sort == 0 && ft_get_slen(s->a) > 3)
	{
		s->sort_from_start = 1;
		return ;
	}
	ft_do_cmd_0("pb", i_max_sort, s);
	s->sort_from_start = 1;
}

int			ft_check_sort(t_stack *s)
{
	t_stack *tmp;
	int		flag;
	int		prev;
	int		first;

	flag = 0;
	tmp = s;
	first = tmp->val;
	prev = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (prev > tmp->val)
			flag++;
		prev = tmp->val;
		if (!tmp->next)
			tmp->val > first ? flag++ : flag;
		tmp = tmp->next;
	}
	return (flag < 2 ? 1 : 0);
}

int			ft_check_unsort(t_stacks *s)
{
	int		prev;
	t_stack	*tmp;

	tmp = s->a;
	prev = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
			return (0);
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}
