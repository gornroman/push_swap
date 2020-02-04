/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:26:38 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_header(t_stacks *s)
{
	int		tmp;

	tmp = 5;
	if (s)
		ft_putstr("*");
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("A");
	tmp = 5;
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("*");
	tmp = 5;
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("B");
	tmp = 5;
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("*\n");
}

void		ft_print_stack(t_stack *a)
{
	int		tmp;

	if (a == NULL)
	{
		tmp = 11;
		while (tmp--)
			ft_putstr(" ");
	}
	else
	{
		tmp = 11 - ft_get_len_of_int(a->val);
		a->val < 0 ? tmp-- : tmp;
		while (tmp > 0)
		{
			ft_putstr(" ");
			tmp--;
		}
		ft_putnbr(a->val);
	}
}

void		ft_print_bot(t_stacks *s)
{
	int		tmp;

	tmp = 11;
	if (s)
		ft_putstr("*");
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("*");
	tmp = 11;
	while ((tmp--))
		ft_putstr("-");
	ft_putstr("*\n");
}

void		ft_print_v_help(t_stack *temp_a, t_stack *temp_b)
{
	ft_putstr("|");
	ft_print_stack(temp_a);
	ft_putstr("|");
	ft_print_stack(temp_b);
	ft_putstr("|\n");
}

void		ft_print_v(t_stacks *s)
{
	int		i;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = s->a;
	temp_b = s->b;
	i = 0;
	ft_print_header(s);
	while (i < ft_get_slen(s->a) || i < ft_get_slen(s->b))
	{
		ft_print_v_help(temp_a, temp_b);
		i++;
		if (temp_a && temp_a->next)
			temp_a = temp_a->next;
		else
			temp_a = NULL;
		if (temp_b && temp_b->next)
			temp_b = temp_b->next;
		else
			temp_b = NULL;
	}
	ft_print_bot(s);
}
