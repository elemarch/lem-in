/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libdlst.h"
#include "libft.h"

void		str_add(t_str *s, char *c)
{
	t_dlst_link *lk;

	if (!s || !c || !*c)
		return ;
	if (str_tryexpand(s))
	{
		if (!(lk = dlst_push_back(&s->lst)))
			return ;
	}
	else
		lk = s->lst.end;
	lk->content = ft_strdups(c, &lk->content_size);
	s->size += lk->content_size;
	s->valid = FALSE;
}

void		str_adds(t_str *s, t_str *c)
{
	if (!s || !c || c->size == 0)
		return ;
	dlst_merge(&(s->lst), &(c->lst), ft_memdup);
	str_fixsize(s);
	s->valid = FALSE;
}
