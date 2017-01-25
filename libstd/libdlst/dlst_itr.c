/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_itr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 04:30:34 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/17 18:15:31 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void	dlst_foreach(t_dlst *dlst, void (*f)(t_dlst_link *))
{
	t_dlst_link *lnk;

	if (!dlst || !dlst->link)
		return ;
	lnk = dlst->link;
	while (lnk)
	{
		f(lnk);
		lnk = lnk->next;
	}
}

void	dlst_foreach_ex(t_dlst *lst, void *ex, void (*f)(t_dlst_link *, void *))
{
	t_dlst_link	*lnk;

	if (!lst || !lst->link)
		return ;
	lnk = lst->link;
	while (lnk)
	{
		f(lnk, ex);
		lnk = lnk->next;
	}
}
