/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:54:56 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 07:42:55 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void		dlst_reindex(t_dlst *dlst)
{
	size_t		i;
	t_dlst_link	*lnk;

	if (!dlst || !dlst->link)
		return ;
	lnk = dlst->link;
	i = 0;
	while (lnk)
	{
		lnk->dlst = dlst;
		lnk->index = i++;
		if (!lnk->next)
			dlst->end = lnk;
		lnk = lnk->next;
	}
	dlst->size = i;
}

void		dlst_lnk_reindex(t_dlst_link *lnk, t_dlst *dlst)
{
	size_t		i;

	if (!lnk || !dlst)
		return ;
	i = 0;
	while (lnk)
	{
		lnk->index = i++;
		lnk->dlst = dlst;
		if (!lnk->next)
			dlst->end = lnk;
		lnk = lnk->next;
	}
}
