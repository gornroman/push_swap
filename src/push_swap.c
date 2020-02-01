/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/31 16:09:12 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_stack(t_stack **s)
{
	t_stack		*temp;

	temp = *s;
	while (temp != NULL)
	{
		printf("%d ", (temp)->val);
		(temp) = (temp)->next;
	}
	printf("\n");
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
void		ft_print_stack2(t_stacks *s)
{
	t_stack		*a;
	t_stack		*b;

	a = s->a;
	b = s->b;
	while (a != NULL || b != NULL)
	{
		printf("%d   ", a->val);
		if (!b)
			printf("x\n");
		if (b)
		{
			printf("%d\n", b->val);
			b = b->next;
		}
		a = a->next;
	}
	printf("\n");
}

int				ft_get_slen(t_stack *s)
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

void		ft_print_stack3(t_stacks *s)
{
	t_stack		*a;
	t_stack		*b;
	int 		len;

	len = ft_get_slen(s->a) > ft_get_slen(s->b) ? ft_get_slen(s->a) : ft_get_slen(s->b);
	a = s->a;
	b = s->b;
	while (len--)
	{
		if (!a)
			printf("    ");
		else
		{
			printf("%d   ", a->val);
			a = a->next;
		}
		if (!b)
			printf("x\n");
		else
		{
			printf("%d\n", b->val);
			b = b->next;
		}
	}
	printf("\n");
}

int 		ft_find_i_max_sort(t_stack *s)
{
	int 	max;
	int 	prev;
	int 	new_max;
	int		ind;

	ind = 0;
	prev = s->val;
	new_max = 0;
	max = 0;
	s = s->next;
	while (s)
	{
		if (s->val > prev)
		{
			new_max++;
			if (new_max > max)
			{
				max = new_max;
				ind = s->i - max;
			}
		}
		else
			new_max = 0;
		prev = s->val;
		s = s->next;
	}
	return (ind);
}

void		ft_print_cmd(char	*cmd)
{
	ft_putstr(cmd);
	ft_putchar('\n');
}

void		ft_move_unsort(t_stacks *s)
{
	int 	i_max_sort;

	ft_index(s->a);
//	i_max_sort = ft_get_slen(s->a) - ft_find_i_max_sort(s->a) >= 3 ? ft_find_i_max_sort(s->a) : ;
	if (ft_get_slen(s->a) - ft_find_i_max_sort(s->a) >= 3)
		i_max_sort = ft_find_i_max_sort(s->a);
	else
		i_max_sort = ft_get_slen(s->a) - 3;
//	printf("index: %d\n", i_max_sort);
//	while (i_max_sort--)
	ft_do_cmd_0("pb", i_max_sort, s);
}

int 		ft_find_i_after_sort2(t_stack *s)
{
	int 	max;
	int 	prev;
	int 	new_max;
	int		ind;

	ind = 0;
	prev = s->val;
	new_max = 0;
	max = 0;
	s = s->next;
	while (s)
	{
		if (s->val > prev)
		{
			new_max++;
			if (new_max > max)
			{
				max = new_max;
				ind = s->i;
			}
		}
		else
			new_max = 0;
		prev = s->val;
		s = s->next;
	}
	return (ind + 1);
}

int 		ft_find_i_after_sort(t_stack *s)
{
	int 	i;
	int 	prev;
	int 	i_after_sort;

	prev = s->val;
	i_after_sort = 0;
	i = 0;
	s = s->next;
	while (s)
	{
		if (s->val > prev)
			i_after_sort = i;
		else
			i_after_sort = 0;
		prev = s->val;
		s = s->next;
		i++;
	}
	return (i_after_sort + 1);
}

void		ft_move_unsort_2(t_stacks *s)
{
	int		i;

	if (ft_find_i_after_sort2(s->a) < 3)
		i = ft_get_slen(s->a) - 3;
	else
		i = ft_get_slen(s->a) - ft_find_i_after_sort2(s->a);
	ft_do_cmd_0("rra", i, s);
	ft_do_cmd_0("pb", i, s);
}

void	ft_sort_3(t_stacks *s)
{
	if (s->a->val > s->a->next->val && s->a->val < s->a->next->next->val)
		ft_do_cmd_0("sa", 1, s);
	else if (s->a->val > s->a->next->next->val)
		ft_do_cmd_0("rra", 1, s);
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
	else if (ft_get_slen(s->a) == 5 && ft_is_sorted_1(s->a) == 0)
		printf("5elemetns algo\n");
	else if (ft_is_sorted_1(s->a) == 0)
	{
		ft_print_stack3(s);
		ft_move_unsort(s);
		ft_print_stack3(s);
		ft_index(s->a);
		ft_move_unsort_2(s);
		ft_print_stack3(s);
		if (ft_is_sorted_1(s->a) == 0)
			ft_sort_3(s);
//		ft_print_stack3(s);
	}
}

int			main(int argc, char **argv)
{
	t_stacks	*s;

	s = ft_create_stack(argc, argv);
	s->flag_print = 1;
	ft_start_pushing(s);
	return (1);
}

