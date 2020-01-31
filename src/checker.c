/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/31 15:54:57 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_not_dub(t_stack *s, int value)
{
	while (s)
	{
		if (s->val == value)
			return (0);
		s = s->next;
	}
	return (1);
}

static void	ft_stack_free(t_stack **s)
{
	t_stack	*next;

	while (*s)
	{
		next = (*s)->next;
		free(*s);
		*s = next;
	}
}

int			ft_stacks_free(t_stacks **s)
{
	if (*s && (*s)->a)
		ft_stack_free(&(*s)->a);
	if (*s && (*s)->b)
		ft_stack_free(&(*s)->b);
	if (*s)
		free(*s);
	return (1);
}

void		ft_put_error(t_stacks **s)
{
	ft_putstr("Error\n");
	ft_stacks_free(s);
	exit(1);
}

t_stack		*ft_create_new_n(int val)
{
	t_stack *new;

	if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack 	*ft_last_node(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

t_stack		*ft_stack_push_back(t_stack **stack, int val)
{
	t_stack	*new;
	t_stack	*last;

	if ((new = ft_create_new_n(val)) == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}
	last = ft_last_node(*stack);
	last->next = new;
	return (*stack);
}

void		ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array && *array)
		free(array);
}

int			ft_check_int(int val_i, char *val_c)
{
	char	*val;
	int		res;

	res = 0;
	val = ft_itoa(val_i);
	if (ft_strcmp(val, val_c) == 0)
		res = 1;
	if (val)
		free(val);
	return (res);
}

void		ft_create_stack_a(int argc, char **argv, t_stacks *s)
{
	int 	i;
	int 	cur_value;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			s->flag_v = 1;
		else
		{
			cur_value = ft_atoi(argv[i]);
			if (ft_is_not_dub(s->a, cur_value) == 0)
				ft_put_error(&s);
			if (ft_stack_push_back(&s->a, cur_value) == NULL)
				ft_put_error(&s);
			if (ft_check_int(cur_value, argv[i]) == 0)
				ft_put_error(&s);
		}
		i++;
	}
//	ft_free_array(argv);
}

//#include <stdio.h>
void		ft_create_stack_a_argc2(char **argv, t_stacks *s)
{
	int 	i;
	int 	cur_value;

//	printf("%s\n", argv[1]);
	argv = ft_strsplit(argv[1], ' ');
//	printf("%s %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);
	i = 0;
	while ((int)argv[i])
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			s->flag_v = 1;
		else
		{
			cur_value = ft_atoi(argv[i]);
			if (ft_is_not_dub(s->a, cur_value) == 0)
				ft_put_error(&s);
			if (ft_stack_push_back(&s->a, cur_value) == NULL)
				ft_put_error(&s);
		}
		i++;
	}
	ft_free_array(argv);
}

t_stacks	*ft_create_stack(int argc, char **argv)
{
	t_stacks	*s;

	s = (t_stacks*)malloc(sizeof(t_stacks));
	if (!s)
		return (NULL);
	s->a = NULL;
	s->b = NULL;
//	s->flag_v = 0;
	s->cmd_counter = 0;
	s->flag_print = 0;
	if (argc == 2)
		ft_create_stack_a_argc2(argv, s);
	else
		ft_create_stack_a(argc, argv, s);
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

int 		ft_cmd_s(t_stack **s)
{
	int 	temp;

	if (*s && (*s)->next)
	{
		temp = (*s)->val;
		(*s)->val = (*s)->next->val;
		(*s)->next->val = temp;
		return (1);
	}
	return (-1);
}

t_stack 	*ft_pop_first(t_stack **s)
{
	t_stack		*temp;

	if (*s == NULL)
		return (NULL);
	temp = *s;
	if ((*s)->next == NULL)
		*s = NULL;
	else
		*s = temp->next;
	temp->next = NULL;
	return (temp);
}

void		ft_push_first(t_stack **s, t_stack *new)
{
	if (*s == NULL)
		*s = new;
	else
	{
		new->next = *s;
		*s = new;
	}
}

int 		ft_cmd_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_push_first(to, ft_pop_first(from));
		return (1);
	}
	return (-1);
}

t_stack 	*ft_get_last(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

void		ft_push_last(t_stack **s, t_stack *new)
{
	t_stack		*last;

	if (*s == NULL)
	{
		*s = new;
		return ;
	}
	last = ft_get_last(*s);
	last->next = new;
}

int 		ft_cmd_r(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_last(s, ft_pop_first(s));
		return (1);
	}
	return (-1);
}

t_stack 	*ft_pop_last(t_stack **s)
{
	t_stack		*pre;
	t_stack		*temp;

	pre = *s;
	temp = *s;
	if (*s == NULL)
		return (NULL);
	if ((*s)->next == NULL)
		*s = NULL;
	else
	{
		while(pre->next && pre->next->next)
			pre = pre->next;
		temp = pre->next;
		pre->next = NULL;
	}
	return (temp);
}

int 		ft_cmd_rr(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_first(s, ft_pop_last(s));
		return (1);
	}
	return (-1);
}

int 		ft_do_cmd(char *cmd, t_stacks *s)
{
	int		len;
	int 	res;

	len = ft_strlen(cmd);
	res = 0;
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
		res = ft_cmd_s(&s->a);
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
		res = ft_cmd_s(&s->b);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'a')
		res = ft_cmd_p(&s->b, &s->a);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'b')
		res = ft_cmd_p(&s->a, &s->b);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
		res = ft_cmd_r(&s->b);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		res = ft_cmd_r(&s->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' && (cmd[2] == 'r' || cmd[2] == 'a'))
		res = ft_cmd_rr(&s->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' && (cmd[2] == 'r' || cmd[2] == 'b'))
		res = ft_cmd_rr(&s->b);
	return (res == 0 ? 0 : 1);
}

void		ft_do_cmd_0(char *com, int rpt, t_stacks *s)
{
//	int	i;
//
//	i = ft_abs(cnt);
	while (rpt)
	{
		if (ft_do_cmd(com, s))
		{
			if (s->flag_print == 1)
				ft_print_cmd(com);
//			if (s->cmd_print == 0 && s->flag_v == 1)
//				ft_ps_print_stack(s);
			s->cmd_counter++;
		}
		else
			ft_put_error(&s);
		rpt--;
	}
}

//int			main(int argc, char **argv)
//{
//	t_stacks	*s;
//	char		*cmd;
//
//	cmd = NULL;
//	s = ft_create_stack(argc, argv);
//	if (s->a == NULL)
//	{
//		ft_put_error(&s);
//		return (0);
//	}
//	while (get_next_line(0, &cmd))
//	{
//		if (ft_do_cmd(cmd, s) == 0)
//			ft_put_error(&s);
//		if (cmd)
//			free(cmd);
//	}
//	if (ft_is_sorted(s))
//		ft_putstr("OK\n");
//	else
//		ft_putstr("KO\n");
//	return (1);
//}
