/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:53:39 by esaminad          #+#    #+#             */
/*   Updated: 2015/01/20 15:18:02 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst_link	*dlst_push_back_c(t_dlst *dlst, void *cont, size_t sz)
{
	t_dlst_link *lk;

	if (!dlst)
		return (NULL);
	if (!(lk = dlst_push_back(dlst)))
		return (NULL);
	dlst_lnk_set_cont(lk, cont, sz);
	return (lk);
}

t_dlst_link	*dlst_push_back(t_dlst *dlst)
{
	t_dlst_link	*lk;
	t_dlst_link *prev;

	if (!dlst)
		return (NULL);
	prev = dlst_last(dlst);
	if (!(lk = dlst_lnk_new()))
		return (NULL);
	if (prev)
	{
		lk->prev = prev;
		prev->next = lk;
	}
	if (!prev)
		dlst->link = lk;
	dlst->size = dlst->size + 1;
	dlst_reindex(dlst);
	return (lk);
}

void		dlst_pop_back(t_dlst *dlst)
{
	t_dlst_link *lnk;

	if (!dlst)
		return ;
	if (!(lnk = dlst_last(dlst)))
		return ;
	if (lnk->content)
		FREE(lnk->content);
	if (lnk->prev)
	{
		dlst->end = lnk->prev;
		lnk->prev->next = NULL;
	}
	FREE(lnk);
	dlst->size = dlst->size - 1;
}

void		dlst_erase(t_dlst *dlst, size_t at)
{
	t_dlst_link	*lnk;

	if (!dlst || !dlst->link || dlst->size == 0)
		return ;
	lnk = dlst_at(dlst, at);
	if (!lnk)
		return ;
	if (lnk->prev)
		lnk->prev->next = lnk->next;
	if (lnk->next)
		lnk->next->prev = lnk->prev;
	if (lnk->content)
		FREE(lnk->content);
	dlst->size = dlst->size - 1;
	dlst_reindex(dlst);
}
