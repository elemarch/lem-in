/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:54:13 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:54:13 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst_link	*dlst_emplace(t_dlst *dlst, size_t at)
{
	t_dlst_link *lnk;
	t_dlst_link *prev;
	t_dlst_link *next;

	if (!dlst)
		return (NULL);
	prev = dlst_at(dlst, at - 1);
	next = dlst_at(dlst, at);
	lnk = dlst_lnk_gen(NULL, 0, at == 0 ? NULL : prev, next);
	if (prev)
		prev->next = lnk;
	if (next)
		next->prev = lnk;
	if (at == 0)
		dlst->link = lnk;
	dlst->size = dlst->size + 1;
	dlst_reindex(dlst);
	return (dlst_at(dlst, at));
}

t_dlst_link	*dlst_insert(t_dlst *dlst, size_t at)
{
	if (at == 0)
		return (dlst_emplace(dlst, at));
	return (dlst_emplace(dlst, at - 1));
}

void		dlst_swap(t_dlst *dlst, size_t pos1, size_t pos2)
{
	t_dlst_link	*l1;
	t_dlst_link	*l2;
	t_dlst_link	*tmp1;
	t_dlst_link	*tmp2;

	l1 = dlst_at(dlst, pos1);
	l2 = dlst_at(dlst, pos2);
	if (!l1 || !l2)
		return ;
	tmp1 = l1->next;
	tmp2 = l1->prev;
	l1->next = l2->next;
	l1->prev = l2->prev;
	l2->next = tmp1;
	l2->prev = tmp2;
	dlst_reindex(dlst);
}

void		dlst_rev(t_dlst *dlst)
{
	t_dlst_link	*tmp;
	t_dlst_link	*itr;

	if (!dlst)
		return ;
	if (!dlst->link)
		return ;
	itr = dlst->link;
	while (itr)
	{
		tmp = itr->next;
		itr->next = itr->prev;
		itr->prev = tmp;
		if (!tmp)
			break ;
		itr = tmp;
	}
	dlst->link = itr;
	dlst_reindex(dlst);
}

void		dlst_merge(t_dlst *dst, t_dlst *src, void *(*cpy)(void*))
{
	t_dlst_link *lks;

	if (!dst || !src || src->size == 0 || !cpy)
		return ;
	lks = src->link;
	while (lks)
	{
		dlst_push_back_c(dst, cpy(lks->content), lks->content_size);
		lks = lks->next;
	}
}
