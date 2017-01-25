/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

t_bool		str_trylinkexpand(t_dlst_link *lk)
{
	if (!lk)
		return (FALSE);
	if (!lk->content || lk->content_size < STR_EXPAND_THRESHOLD)
		return (TRUE);
	return (FALSE);
}

void		str_flatten(t_str *s)
{
	char *str;

	if (!s || str_isnull(s))
		return ;
	str = str_toc(s);
	str_clear(s);
	str_add(s, str);
	str_setdata(s, str);
}

void		str_setdata(t_str *s, char *c)
{
	s->valid = TRUE;
	s->data = c;
}
