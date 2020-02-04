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

int 		ft_last_elem(t_stack *a)
{
	while(a && a->next)
		a = a->next;
	return (a->val);
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
//	if (i_max_sort == 0 && ft_get_slen(s->a) > 3)
//		i_max_sort = ft_get_slen(s->a) - 3;
	if (i_max_sort == 0 && ft_get_slen(s->a) > 3)
	{
		s->sort_from_start = 1;
		return ;
	}
	ft_do_cmd_0("pb", i_max_sort, s);
	s->sort_from_start = 1;
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

void		ft_move_unsort_2(t_stacks *s)
{
	int		i;

	if (ft_is_sorted_1(s->a))
		return ;
	if (ft_find_i_after_sort2(s->a) < 3)
		i = ft_get_slen(s->a) - 3;
	else
		i = ft_get_slen(s->a) - ft_find_i_after_sort2(s->a);
//	ft_do_cmd_0("rra", i, s);

	if (ft_find_i_after_sort2(s->a) >= 3)
	{
		ft_do_cmd_0("ra", ft_get_slen(s->a) - i, s);
		ft_do_cmd_0("pb", i, s);
	}
	else
	{
		ft_do_cmd_0("ra", 2, s);
		ft_do_cmd_0("pb", i, s);
	}
}

int		ft_check_sort(t_stack *s)
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

void		ft_move_unsort_3(t_stacks *s)
{
	int		i;

	if (ft_is_sorted_1(s->a))
		return ;
	if (ft_find_i_after_sort2(s->a) < 3)
		i = ft_get_slen(s->a) - 3;
	else
		i = ft_get_slen(s->a) - ft_find_i_after_sort2(s->a);
//	ft_do_cmd_0("rra", i, s);

	if (ft_find_i_after_sort2(s->a) >= 3)
	{
		//проверить наличие такого же отсортированного участка в самом конце стака
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
	else
	{
		if (ft_check_unsort(s) == 0)
			ft_do_cmd_0("ra", i, s);
		ft_do_cmd_0("pb", i, s);
	}
}

void	ft_sort_3_2(t_stacks *s)
{
	if (s->a->val > s->a->next->val &&
		s->a->val < s->a->next->next->val)
		ft_do_cmd_0("sa", 1, s);
	else if (s->a->val > s->a->next->next->val)
		ft_do_cmd_0("ra", 1, s);
}

void		ft_sort_3(t_stacks *s)
{
//	printf("start ft_sort_3\n");
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
//	printf("finish ft_sort_3\n");
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

//	if (s->tmp_b->val < s->a->val)
//		return (0);
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
//		if (a_temp->next == NULL && s->tmp_b->val > a_temp->val)
//			return (0);
		a_temp = a_temp->next;
	}
//	return (ft_get_slen(s->a));
	return (0);
}

int 		ft_find_comb(t_stacks *s, int a_ind)
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

int 		ft_find_comb_bigger5(t_stacks *s, int a_ind)
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
//	way = min + (max - min) + 1 + a_ind;
	way = min + (max - min) + 1;
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
//	way = (len_max - max);
	way = (len_min - min);
//	way = s->len_a == a_ind ? way + 2 : way + ((len_min - min) - (len_max - max)) + 1 + (len_min - min + 1);
//	way = s->len_a == a_ind ? way + 2 : way + ((len_min - min) - (len_max - max)) + 1;
	way = way + ((len_max - max) - (len_min - min)) + 1;
	return (way);
}

int 		ft_find_route3(t_stacks *s, int a_ind)
{
	int 	way;

//	way = a_ind + (s->len_b - s->tmp_b->i) + 1 + a_ind;
//	a_ind == 0 ? way : way++;
	way = a_ind + (s->len_b - s->tmp_b->i) + 1;
	return (way);
}

int 		ft_find_route4(t_stacks *s, int a_ind)
{
	int 	way;

//	way = (s->len_a - a_ind) + s->tmp_b->i + 1 + (s->len_a - a_ind - 1);
//	a_ind == 0 ? way : way++;
	way = (s->len_a - a_ind) + s->tmp_b->i + 1;
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
	if (s->firstlen > 5)
		comb = ft_find_comb_bigger5(s, a_ind);
	else
		comb = ft_find_comb(s, a_ind);//узнать расположение А и Б (1/2/3/4)
	min_route = ft_find_route(s, comb, a_ind);//считать маршрут (1/2/3/4)
	s->tmp_comb = comb;
	s->tmp_ind_a = a_ind;
	s->tmp_ind_b = s->tmp_b->i;
//	printf("s->b val: %d, ", s->tmp_b->val);
//	printf("a_len: %d, a_ind: %d, b_len: %d, b_ind: %d, comb: %d, ", s->len_a, a_ind, s->len_b, s->tmp_b->i, comb);
//	printf("min_route: %d\n", min_route);

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
//		ft_do_cmd_0("rra", s->ind_a, s);
	}
	else
	{
		ft_do_cmd_0("rr", min, s);
		ft_do_cmd_0(cmd, (max - min), s);
		ft_do_cmd_0("pa", 1, s);
//		ft_do_cmd_0("rra", s->ind_a, s);
	}
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
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
//	if (s->len_b == 1)
//	{
//		ft_do_cmd_0("ra", (s->len_a - (len_min - min)), s);
//		ft_do_cmd_0("pa", 1, s);
//		return ;
//	}
	ft_do_cmd_0("rrr", (len_max - max), s);
	if (s->len_a == s->ind_a && s->ind_b == 0)
	{
		ft_do_cmd_0("pa", 1, s);
//		ft_do_cmd_0("ra", 1, s);
	}
	else
	{
		ft_do_cmd_0(cmd, ((len_min - min) - (len_max - max)), s);
		ft_do_cmd_0("pa", 1, s);
//		ft_do_cmd_0("ra", (s->len_a - s->ind_a + 1), s);
	}
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
}

void 		ft_do_route3(t_stacks *s)
{
	ft_do_cmd_0("ra", s->ind_a, s);
	if (s->len_b > 1)
		ft_do_cmd_0("rrb", (s->len_b - s->ind_b), s);
	ft_do_cmd_0("pa", 1, s);
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
//	ft_do_cmd_0("rra", s->ind_a, s);
}

void 		ft_do_route4(t_stacks *s)
{
	ft_do_cmd_0("rra", (s->len_a - s->ind_a), s);
	ft_do_cmd_0("rb", s->ind_b, s);
	ft_do_cmd_0("pa", 1, s);
	if (s->a->val > s->a->next->val)
		ft_do_cmd_0("ra", 1, s);
//	ft_do_cmd_0("ra", (s->len_a - s->ind_a + 1), s);
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
//	printf("ind_b: %d, ind_a: %d, comb: %d\n", s->ind_b, s->ind_a, s->comb);
//	ft_print_stack3(s);
	ft_move_to_a(s);
//	ft_print_stack3(s);
	//переводим из стака б в а min_i
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
	int 	last_elem;

	printf("ft_check_last\n");
	if (ft_check_sort(s->a) == 0)
		return ;
	last_elem = ft_last_elem(s->a);
	while (s->a->val > last_elem)
	{
		ft_do_cmd_0("rra", 1, s);
//		s->a = s->a->next;
		last_elem = ft_last_elem(s->a);
	}
	printf("ft_check_last finish\n");
}

int			ft_find_sorts(t_stack *s, int max)
{
	int		prev;
	int 	sortlen;
	t_stack	*tmp;
	int		res;

	res = 0;
	tmp = s;
	prev = tmp->val;
	tmp = tmp->next;
	sortlen = 1;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			sortlen++;
			if (sortlen == max)
				res++;
		}
		else
			sortlen = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (res);
}

int 		ft_count_sorts(t_stack *s)
{
	int 	max;
	int 	prev;
	int 	new_max;
	t_stack	*tmp;

	tmp = s;
	prev = tmp->val;
	new_max = 1;
	max = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			new_max++;
			if (new_max > max)
				max = new_max;
		}
		else
			new_max = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (ft_find_sorts(s, max));
}

int		ft_find_last_2(t_stack *s, int max)
{
	t_stack	*tmp;
	int		prev;
	int 	count_sort;

	tmp = s;
	count_sort = 1;
	prev = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			count_sort++;
			if (count_sort == max)
				return (tmp->i);
		}
		else
			count_sort = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (0);
}

int			ft_find_last(t_stack *s)
{
	int 	max;
	int 	prev;
	int 	new_max;
	t_stack	*tmp;

	tmp = s;
	prev = tmp->val;
	new_max = 1;
	max = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			new_max++;
			if (new_max > max)
				max = new_max;
		}
		else
			new_max = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (ft_find_last_2(s, max));
}

int			ft_find_len_of_sort(t_stack *s)
{
	int 	max;
	int 	prev;
	int 	new_max;
	t_stack	*tmp;

	tmp = s;
	prev = tmp->val;
	new_max = 1;
	max = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			new_max++;
			if (new_max > max)
				max = new_max;
		}
		else
			new_max = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

void 		ft_first_sort_one(t_stacks *s)
{
	int 	last_of_sort;
	int 	len_of_sort;
	int 	before_sort;
	int 	after_sort;

	last_of_sort = ft_find_last(s->a) + 1;
//	printf("last of first sort: %d\n", last_of_sort);
	len_of_sort = ft_find_len_of_sort(s->a);
//	printf("len of sort: %d\n", len_of_sort);
	before_sort = last_of_sort - len_of_sort;
//	printf("before sort: %d\n", before_sort);
	after_sort = ft_get_slen(s->a) - last_of_sort;
//	printf("after sort: %d\n", after_sort);
	if ((before_sort + len_of_sort + after_sort) < (after_sort + after_sort + before_sort))
	{
//		printf("1.1st var\n");
		ft_do_cmd_0("pb", before_sort, s);
		ft_do_cmd_0("ra", len_of_sort, s);
		while (after_sort)
		{
			if (s->a->val < ft_last_elem(s->a)  && ft_get_slen(s->a) > 3)
				ft_do_cmd_0("pb", 1, s);
			else if (ft_get_slen(s->a) > 3)
				ft_do_cmd_0("ra", 1, s);

			if (ft_check_sort(s->a) == 1)
				return ;
			after_sort--;
		}
	}
	else
	{
//		printf("1.2nd var\n");
		ft_do_cmd_0("rra", after_sort, s);
		while (after_sort)
		{
			if (s->a->val < ft_last_elem(s->a) && ft_get_slen(s->a) > 3)
				ft_do_cmd_0("pb", 1, s);
			else if (ft_get_slen(s->a) > 3)
				ft_do_cmd_0("ra", 1, s);

			if (ft_check_sort(s->a) == 1)
				return ;
			after_sort--;
		}
		while (before_sort)
		{
			if (s->a->val < ft_last_elem(s->a) && ft_get_slen(s->a) > 3)
				ft_do_cmd_0("pb", 1, s);
			else if (ft_get_slen(s->a) > 3)
				ft_do_cmd_0("ra", 1, s);

			if (ft_check_sort(s->a) == 1)
				return ;
			before_sort--;
		}
	}
}

int			ft_get_last_sort(t_stacks *s, int max)
{
	t_stack	*tmp;
	int		prev;
	int 	count_sort;
	int 	res;

	res = 0;
	tmp = s->a;
	count_sort = 1;
	prev = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > prev)
		{
			count_sort++;
			if (count_sort == max)
				res = tmp->i + 1;
		}
		else
			count_sort = 1;
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (res);
}

void		ft_help_pb(t_stacks *s, int count)
{
	while (count)
	{
		if (s->a->val < ft_last_elem(s->a) && ft_get_slen(s->a) > 3)
			ft_do_cmd_0("pb", 1, s);
		else if (ft_get_slen(s->a) > 3)
			ft_do_cmd_0("ra", 1, s);

		if (ft_check_sort(s->a) == 1)
			return ;
		count--;
	}
}

void		ft_first_sort_many(t_stacks *s)
{
	int 	last_of_sort;
	int 	len_of_sort;
	int 	before_first_sort;
	int 	after_first_sort;
	int 	last_of_last_sort;
	int 	len_of_a;

	len_of_a = ft_get_slen(s->a);
//	printf("many sorts\n");
	last_of_sort = ft_find_last(s->a) + 1;
//	printf("last of first sort: %d\n", last_of_sort);
	len_of_sort = ft_find_len_of_sort(s->a);
//	printf("len of sort: %d\n", len_of_sort);
	before_first_sort = last_of_sort - len_of_sort;
//	printf("before first sort: %d\n", before_first_sort);
	after_first_sort = ft_get_slen(s->a) - last_of_sort;
//	printf("after first sort: %d\n", after_first_sort);
	last_of_last_sort = ft_get_last_sort(s, len_of_sort);
//	printf("last of last sort: %d\n", last_of_last_sort);
	if ((before_first_sort + len_of_sort + (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort)) + len_of_sort + (len_of_a - last_of_last_sort))
		< (2 * (len_of_a - last_of_last_sort) + before_first_sort + len_of_sort + (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort))))
	{
//		printf("2.1 var\n");
//		ft_do_cmd_0("pb", before_first_sort, s);
//		ft_do_cmd_0("ra", len_of_sort, s);
//		ft_do_cmd_0("pb", (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort)), s);
//		ft_do_cmd_0("pb", len_of_sort, s);
//		ft_do_cmd_0("pb", (len_of_a - last_of_last_sort), s);

//		ft_help_pb(s, before_first_sort);
		ft_do_cmd_0("pb", before_first_sort, s);
		ft_do_cmd_0("ra", len_of_sort, s);
		ft_help_pb(s, (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort)));
		ft_help_pb(s, len_of_sort);
		ft_help_pb(s, (len_of_a - last_of_last_sort));
	}
	else
	{
//		printf("2.2 var\n");
//		ft_do_cmd_0("rra", (len_of_a - last_of_last_sort), s);
//		ft_do_cmd_0("pb", (len_of_a - last_of_last_sort), s);
//		ft_do_cmd_0("pb", before_first_sort, s);
//		ft_do_cmd_0("pb", len_of_sort, s);
//		ft_do_cmd_0("pb", (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort)), s);
		ft_do_cmd_0("rra", (len_of_a - last_of_last_sort), s);
		ft_help_pb(s, (len_of_a - last_of_last_sort));
		ft_help_pb(s, before_first_sort);
		ft_help_pb(s, len_of_sort);
		ft_help_pb(s, (len_of_a - before_first_sort - 2 * len_of_sort - (len_of_a - last_of_last_sort)));
//		printf("2.2 var finish\n");
	}
}

void		ft_first_sort(t_stacks *s)
{
	ft_index(s->a);
	if (ft_count_sorts(s->a) == 0)
	{
		ft_do_cmd_0("pb", ft_get_slen(s->a) - 3, s);
		return ;
	}
	if (ft_count_sorts(s->a) == 1)
		ft_first_sort_one(s);
	else
		ft_first_sort_many(s);
}

void		ft_start_pushing(t_stacks *s)
{
	if (ft_get_slen(s->a) == 2 && ft_is_sorted_1(s->a) == 0)
		ft_do_cmd_0("sa", 1, s);
	else if (ft_get_slen(s->a) == 3 && ft_is_sorted_1(s->a) == 0)
		ft_sort_3(s);
//	else if (ft_get_slen(s->a) == 5 && ft_is_sorted_1(s->a) == 0)
//		printf("5elemetns algo\n");
	else if (ft_is_sorted_1(s->a) == 0)
	{
		ft_first_sort(s);
//		// прошлый вариант:
//		ft_move_unsort(s);
//		ft_check_last(s);
//		ft_index(s->a);
//		s->sort_from_start == 1 ? ft_move_unsort_3(s) : ft_move_unsort(s);
		if (ft_is_sorted_1(s->a) == 0 && ft_get_slen(s->a) == 3)
			ft_sort_3(s);
//		ft_print_stack4(s);
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
//	ft_print_stack4(s);
}

int			main(int argc, char **argv)
{
	t_stacks	*s;

	s = ft_create_stack(argc, argv);
	s->flag_print = 1;
	ft_start_pushing(s);
//	printf("CMD_COUNTS: %d\n", s->cmd_counter);
	ft_stacks_free(&s);
	return (1);
}

