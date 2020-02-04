/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:34:31 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stack_free(t_stack **s)
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

t_stack		*ft_create_new_n(int val)
{
	t_stack *new;

	if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->next = NULL;
	return (new);
}

t_stack		*ft_last_node(t_stack *s)
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
