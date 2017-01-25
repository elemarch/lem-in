/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libdlst.h"

void	str_del(t_str **s)
{
	if (!s || !*s)
		return ;
	dlst_clear(&((*s)->lst));
	FREE((*s)->data);
	FREE(*s);
	*s = NULL;
}

void	str_clear(t_str *s)
{
	if (!s || str_isnull(s))
		return ;
	dlst_clear(&(s->lst));
	FREE(s->data);
	s->data = NULL;
	s->size = 0;
	s->valid = FALSE;
}
