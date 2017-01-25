/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:44:56 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/08 16:26:49 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "liblst.h"

t_list		*lst_new(void const *content, size_t content_size)
{
	t_list *n;

	if (!(n = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		n->content = (void *)ft_memalloc(content_size + 1);
		ft_memcpy(n->content, content, content_size);
		n->content_size = content_size;
	}
	else
	{
		n->content = NULL;
		n->content_size = 0;
	}
	n->next = NULL;
	return (n);
}

t_list		*lst_n(void const *content, size_t content_size)
{
	return (lst_new(content, content_size));
}
