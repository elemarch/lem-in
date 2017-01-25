/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 04:26:18 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 04:27:05 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void	dlst_clear(t_dlst *dlst)
{
	t_dlst_link	*lk;

	if (!dlst || dlst->size == 0 || !dlst->link)
		return ;
	lk = dlst->end;
	while (lk && lk->prev)
	{
		FREE(lk->content);
		if (lk->prev)
		{
			lk = lk->prev;
			FREE(lk->next);
		}
		else
		{
			FREE(lk);
			lk = NULL;
		}
	}
	dlst->size = 0;
	dlst->link = NULL;
	dlst->end = NULL;
}

void	dlst_fclear(t_dlst *dlst, void (*f)(void *, size_t))
{
	t_dlst_link	*lk;

	if (!dlst || !f)
		return ;
	lk = dlst->link;
	while (lk)
	{
		f(lk->content, lk->content_size);
		lk = lk->next;
	}
	dlst_clear(dlst);
}

void	dlst_lclear(t_dlst *dlst)
{
	t_dlst_link	*lk;

	if (!dlst || dlst->size == 0 || !dlst->link)
		return ;
	lk = dlst->end;
	while (lk && lk->prev)
	{
		if (lk->prev)
		{
			lk = lk->prev;
			FREE(lk->next);
		}
		else
		{
			FREE(lk);
			lk = NULL;
		}
	}
	dlst->size = 0;
	dlst->link = NULL;
	dlst->end = NULL;
}

void	dlst_del(t_dlst **dlst)
{
	if (!dlst || !*dlst)
		return ;
	dlst_clear(*dlst);
	FREE(*dlst);
	*dlst = NULL;
}

void	dlst_fdel(t_dlst **dlst, void (*f)(void *, size_t))
{
	if (!dlst || !f || !*dlst)
		return ;
	dlst_fclear(*dlst, f);
	FREE(*dlst);
	*dlst = NULL;
}
