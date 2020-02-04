/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:31:55 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_create_stack_a3_help(t_stacks *s, char **temp, int j,
		int cur_value)
{
	if (ft_is_not_dub(s->a, cur_value) == 0)
		ft_put_error(&s);
	if (ft_stack_push_back(&s->a, cur_value) == NULL)
		ft_put_error(&s);
	if (ft_check_int(cur_value, temp[j]) == 0)
		ft_put_error(&s);
}

void		ft_create_stack_a3(int argc, char **argv, t_stacks *s)
{
	int		i;
	int		cur_value;
	char	**temp;
	int		j;

	i = 1;
	while (i < argc)
	{
		temp = ft_strsplit(argv[i], ' ');
		j = 0;
		while ((int)temp[j])
		{
			if (ft_strcmp(temp[j], "-v") == 0)
				s->visualisation = 1;
			else
			{
				cur_value = ft_atoi(temp[j]);
				ft_create_stack_a3_help(s, temp, j, cur_value);
			}
			j++;
		}
		i++;
		ft_free_array(temp);
	}
}

t_stacks	*ft_create_stack(int argc, char **argv)
{
	t_stacks	*s;

	s = (t_stacks*)malloc(sizeof(t_stacks));
	if (!s)
		return (NULL);
	s->a = NULL;
	s->b = NULL;
	s->visualisation = 0;
	s->cmd_counter = 0;
	s->flag_print = 0;
	s->sort_from_start = 0;
	ft_create_stack_a3(argc, argv, s);
	if (s->visualisation == 1)
	{
		ft_putstr("START\n");
		ft_print_v(s);
	}
	s->firstlen = ft_get_slen(s->a);
	return (s);
}

int			ft_is_sorted(t_stacks *s)
{
	t_stack	*tmp;
	int		last_value;

	if (s->b != NULL)
		return (0);
	tmp = s->a;
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

int			ft_cmd_s(t_stack **s)
{
	int		temp;

	if (*s && (*s)->next)
	{
		temp = (*s)->val;
		(*s)->val = (*s)->next->val;
		(*s)->next->val = temp;
		return (1);
	}
	return (-1);
}
