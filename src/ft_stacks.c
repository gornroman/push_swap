/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:32:18 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/04 17:34:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_pop_first(t_stack **s)
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

t_stack		*ft_get_last(t_stack *s)
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

t_stack		*ft_pop_last(t_stack **s)
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
		while (pre->next && pre->next->next)
			pre = pre->next;
		temp = pre->next;
		pre->next = NULL;
	}
	return (temp);
}
