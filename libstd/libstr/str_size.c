/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libft.h"

size_t		str_fixsize(t_str *s)
{
	t_dlst_link *lk;

	if (!s)
		return (0);
	s->size = 0;
	if (s->lst.size == 0)
		return (0);
	lk = s->lst.link;
	while (lk)
	{
		s->size += lk->content_size;
		lk = lk->next;
	}
	return (s->size);
}

size_t		str_calcsize(t_str *s)
{
	t_dlst_link	*lk;

	if (!s)
		return (0);
	s->size = 0;
	if (s->lst.size == 0)
		return (0);
	lk = s->lst.link;
	while (lk)
	{
		if (lk->content)
			lk->content_size = ft_strlen((char*)lk->content);
		s->size += lk->content_size;
		lk = lk->next;
	}
	return (s->size);
}

void		str_fixsizelk(t_str *s, t_dlst_link *lk)
{
	if (!s || !lk)
		return ;
	s->size -= lk->content_size;
	s->size += ft_strlen((char*)lk->content);
}
