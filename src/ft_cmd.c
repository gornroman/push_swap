/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:18:42 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_cmd_rr(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_first(s, ft_pop_last(s));
		return (1);
	}
	return (-1);
}

int			ft_do_cmd(char *cmd, t_stacks *s)
{
	int		len;
	int		res;

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
		res = ft_cmd_r(&s->a);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		res = ft_cmd_r(&s->b);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r'
			&& (cmd[2] == 'r' || cmd[2] == 'a'))
		res = ft_cmd_rr(&s->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r'
			&& (cmd[2] == 'r' || cmd[2] == 'b'))
		res = ft_cmd_rr(&s->b);
	return (res == 0 ? 0 : 1);
}

void		ft_do_cmd_0(char *com, int rpt, t_stacks *s)
{
	while (rpt)
	{
		if (ft_do_cmd(com, s))
		{
			if (s->visualisation == 1)
			{
				ft_prnt_cmd(com);
				ft_print_v(s);
			}
			else if (s->flag_print == 1)
				ft_prnt_cmd(com);
			s->cmd_counter++;
		}
		else
			ft_put_error(&s);
		rpt--;
	}
}

int			ft_cmd_r(t_stack **s)
{
	if (*s && (*s)->next)
	{
		ft_push_last(s, ft_pop_first(s));
		return (1);
	}
	return (-1);
}

int			ft_cmd_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_push_first(to, ft_pop_first(from));
		return (1);
	}
	return (-1);
}
