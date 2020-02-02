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

int			main(int argc, char **argv)
{
	t_stacks	*s;
	char		*cmd;

	cmd = NULL;
	s = ft_create_stack(argc, argv);
	if (s->a == NULL)
	{
		ft_put_error(&s);
		return (0);
	}
	while (get_next_line(0, &cmd))
	{
		if (ft_do_cmd(cmd, s) == 0)
			ft_put_error(&s);
		if (cmd)
			free(cmd);
	}
	if (ft_is_sorted(s))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (1);
}
