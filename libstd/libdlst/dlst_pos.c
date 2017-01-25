/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:53:28 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 07:51:23 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst_link	*dlst_at(t_dlst *dlst, size_t index)
{
	t_dlst_link *lk;

	if (!dlst || !dlst->link || dlst->size == 0)
		return (NULL);
	if (index == 0)
		return (dlst->link);
	if (index == dlst->size - 1)
		return (dlst->end);
	if (index > (dlst->size - 1))
		return (NULL);
	lk = dlst->link;
	while (lk)
	{
		if (lk->index == index)
			return (lk);
		lk = lk->next;
	}
	return (lk);
}

void		*dlst_at_cont(t_dlst *dlst, size_t index)
{
	t_dlst_link *lk;

	if ((lk = dlst_at(dlst, index)) == NULL)
		return (NULL);
	return (lk->content ? lk->content : NULL);
}

t_dlst_link	*dlst_first(t_dlst *dlst)
{
	if (!dlst || !dlst->link)
		return (NULL);
	return (dlst->link);
}

t_dlst_link	*dlst_last(t_dlst *dlst)
{
	if (!dlst || !dlst->link)
		return (NULL);
	return (dlst->end);
}
