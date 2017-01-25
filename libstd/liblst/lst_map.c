/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:41:14 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/11 17:28:47 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "liblst.h"

static t_list	*lst_map_n(void *content, size_t size)
{
	t_list *lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst->content = content;
	lst->content_size = size;
	return (lst);
}

t_list			*lst_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *n;
	t_list *begin;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if ((n = lst_map_n(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	begin = n;
	while (lst->next)
	{
		tmp = f(lst->next);
		if ((n->next = lst_map_n(tmp->content, tmp->content_size)) == NULL)
		{
			lst_del(&begin, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		n = n->next;
	}
	return (begin);
}
