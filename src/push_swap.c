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
	if (i_max_sort == 0 && ft_get_slen(s->a) > 3)
		i_max_sort = ft_get_slen(s->a) - 3;
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

//void	ft_sort_3(t_stacks *s)
//{
//	if (s->a->val > s->a->next->val && s->a->val < s->a->next->next->val)
//		ft_do_cmd_0("sa", 1, s);
//	else if (s->a->val > s->a->next->next->val)
//		ft_do_cmd_0("ra", 1, s);
//}

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

int 		ft_find_a_place(t_stacks *s)
{
	int 	prev;
	t_stack	*a_temp;

	if (s->tmp_b->val < s->a->val)
		return (0);
	a_temp = s->a;
	prev = a_temp->val;
	a_temp = a_temp->next;
	while (a_temp)
	{
		if (s->tmp_b->val > prev && s->tmp_b->val < a_temp->val)
			return (a_temp->i);
		prev = a_temp->val;
		a_temp = a_temp->next;
	}
	return (ft_get_slen(s->a));
}

int 		ft_find_comb(t_stacks *s, int a_ind)
{
	if (s->tmp_b->i < s->len_b / 2 && a_ind < s->len_a / 2)
		return (1);
	if (s->tmp_b->i >= s->len_b / 2 && a_ind >= s->len_a / 2)
		return (2);
	if (s->tmp_b->i >= s->len_b / 2 && a_ind < s->len_a / 2)
		return (3);
	if (s->tmp_b->i < s->len_b / 2 && a_ind >= s->len_a / 2)
		return (4);
}
int 		ft_find_route1(t_stacks *s, int a_ind)
{
	int 	way;
	int 	min;
	int 	max;

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
	way = 0;
//	way = way + max + (min - max) + 1 + max;
	way = min + (max - min) + 1 + a_ind;
	return (way);
}

int 		ft_find_route2(t_stacks *s, int a_ind)
{
	int 	way;
	int 	min;
	int 	max;
	int 	len_min;
	int 	len_max;

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
//	way = (len_max - max) + ((len_min - min) - (len_max - max)) + 1 + (len_min - min);
	way = (len_max - max);
	way = s->len_a == a_ind ? way + 2 : way + ((len_min - min) - (len_max - max)) + 1 + (len_min - min + 1);
//	if (s->len_a == a_ind)
//		way = way + 2;
//	else
//		way = way + ((len_min - min) - (len_max - max)) + 1 + (len_min - min + 1);
	return (way);
}

int 		ft_find_route3(t_stacks *s, int a_ind)
{
	int 	way;

	way = a_ind + (s->len_b - s->tmp_b->i) + 1 + a_ind;
	a_ind == 0 ? way : way++;
	return (way);
}

int 		ft_find_route4(t_stacks *s, int a_ind)
{
	int 	way;

	way = (s->len_a - a_ind) + s->tmp_b->i + 1 + (s->len_a - a_ind - 1);
	a_ind == 0 ? way : way++;
	return (way);
}

int 		ft_find_route(t_stacks *s, int comb, int a_ind)
{
	int 	result;

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

int 		ft_swap(t_stacks *s)
{
	int 	min_route;
	int 	a_ind;
	int		comb;

	a_ind = ft_find_a_place(s); //узнать индекс элемента Б в стаке А
	comb = ft_find_comb(s, a_ind); //узнать расположение А и Б (1/2/3/4)
	min_route = ft_find_route(s, comb, a_ind);//считать маршрут (1/2/3/4)
	s->tmp_comb = comb;
	s->tmp_ind_a = a_ind;
	s->tmp_ind_b = s->tmp_b->i;
	printf("s->b val: %d, ", s->tmp_b->val);
	printf("a_len: %d, a_ind: %d, b_len: %d, b_ind: %d, comb: %d, ", s->len_a, a_ind, s->len_b, s->tmp_b->i, comb);
	printf("min_route: %d\n", min_route);

	return (min_route);
}

void		ft_do_route1(t_stacks *s)
{
	int 	min;
	int 	max;
	char 	*cmd;

	cmd = ft_strnew(3);
	if (s->ind_b < s->ind_a)
	{
		min = s->ind_b;
		max = s->ind_a;
		cmd = "ra";
	}
	else
	{
		min = s->ind_a;
		max = s->ind_b;
		cmd = "rb";
	}
	if (s->ind_b == 0)
	{
		ft_do_cmd_0("ra", s->ind_a, s);
		ft_do_cmd_0("pa", 1, s);
		ft_do_cmd_0("rra", s->ind_a, s);
	}
	else
	{
		ft_do_cmd_0("rr", min, s);
		ft_do_cmd_0(cmd, (max - min), s);
		ft_do_cmd_0("pa", 1, s);
		ft_do_cmd_0("rra", s->ind_a, s);
	}
}

void		ft_do_route2(t_stacks *s)
{
	int 	min;
	int 	max;
	int 	len_min;
	int 	len_max;
	char 	*cmd;

	cmd = ft_strnew(4);
	if (s->len_b - s->ind_b < s->len_a - s->ind_a)
	{
		min = s->ind_a;
		len_min = s->len_a;
		max = s->ind_b;
		len_max = s->len_b;
		cmd = "rra";
	}
	else
	{
		min = s->ind_b;
		len_min = s->len_b;
		max = s->ind_a;
		len_max = s->len_a;
		cmd = "rrb";
	}
	ft_do_cmd_0("rrr", (len_max - max), s);
	if (s->len_a == s->ind_a && s->ind_b == 0)
	{
		ft_do_cmd_0("pa", 1, s);
		ft_do_cmd_0("ra", 1, s);
	}
	else
	{
		ft_do_cmd_0(cmd, ((len_min - min) - (len_max - max)), s);
		ft_do_cmd_0("pa", 1, s);
		ft_do_cmd_0("ra", (s->len_a - s->ind_a + 1), s);
	}
}

void 		ft_do_route3(t_stacks *s)
{
//	int 	way;
	ft_do_cmd_0("ra", s->ind_a, s);
	ft_do_cmd_0("rrb", (s->len_b - s->ind_b), s);
	ft_do_cmd_0("pa", 1, s);
	ft_do_cmd_0("rra", s->ind_a, s);
//	way = a_ind + (s->len_b - s->tmp_b->i) + 1 + a_ind;
//	a_ind == 0 ? way : way++;
//	return (way);
}

void 		ft_do_route4(t_stacks *s)
{
//	int 	way;
	ft_do_cmd_0("rra", (s->len_a - s->ind_a), s);
	ft_do_cmd_0("rb", s->ind_b, s);
	ft_do_cmd_0("pa", 1, s);
	ft_do_cmd_0("ra", (s->len_a - s->ind_a + 1), s);
//	way = a_ind + (s->len_b - s->tmp_b->i) + 1 + a_ind;
//	a_ind == 0 ? way : way++;
//	return (way);
}

void 		ft_move_to_a(t_stacks *s)
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

void 		ft_start_swaping(t_stacks *s)
{
	int 	min_steps;
	int 	i;
	int 	min_i;

	s->tmp_b = s->b;
	min_i = 0;
	s->len_a = ft_get_slen(s->a);
	s->len_b = ft_get_slen(s->b);
	i = 0;
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
	printf("ind_b: %d, ind_a: %d, comb: %d\n", s->ind_b, s->ind_a, s->comb);
	ft_print_stack3(s);
	ft_move_to_a(s);
	ft_print_stack3(s);
	//переводим из стака б в а min_i
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
		ft_print_stack3(s);
	}
	while (ft_get_slen(s->b) > 0)
		ft_start_swaping(s);
}

int			main(int argc, char **argv)
{
	t_stacks	*s;

	s = ft_create_stack(argc, argv);
	s->flag_print = 1;
	ft_start_pushing(s);
	printf("CMD_COUNTS: %d\n", s->cmd_counter);
	return (1);
}

