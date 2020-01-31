/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:32:38 by jgroleo           #+#    #+#             */
/*   Updated: 2019/09/23 12:42:56 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t n)
{
	if (n)
		n = 0;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_first;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	new_first = ft_lstnew(new->content, new->content_size);
	if (!new_first)
		return (NULL);
	lst = lst->next;
	head = new_first;
	while (lst != NULL)
	{
		new = f(lst);
		head->next = ft_lstnew(new->content, new->content_size);
		if (!(head->next))
		{
			ft_lstdel(&new_first, ft_del);
			return (NULL);
		}
		head = head->next;
		lst = lst->next;
	}
	return (new_first);
}
