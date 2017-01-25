/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char		*str_atc(t_str *s, size_t pos)
{
	t_dlst_link	*lk;

	if (!s || str_isnull(s) || pos > s->size)
		return (NULL);
	if (s->valid)
		return (&(s->data[pos]));
	lk = s->lst.link;
	while (lk)
	{
		if (lk->content_size < pos)
			return (((char*)lk->content + pos));
		pos -= lk->content_size;
		lk = lk->next;
	}
	return (NULL);
}

t_dlst_link	*str_atlst(t_str *s, size_t *pos)
{
	t_dlst_link	*lk;

	if (!s || str_isnull(s) || *pos > s->size)
		return (NULL);
	lk = s->lst.link;
	if (s->valid)
		return (lk);
	while (lk)
	{
		if (lk->content_size < *pos)
			return (lk);
		*pos -= lk->content_size;
		lk = lk->next;
	}
	return (NULL);
}
