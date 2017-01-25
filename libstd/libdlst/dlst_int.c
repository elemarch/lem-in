/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:52:46 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:52:49 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst_link		*dlst_push_back_int(t_dlst *dlst, int i)
{
	t_dlst_link	*lnk;
	int			*j;

	if (!dlst)
		return (NULL);
	if ((lnk = dlst_push_back(dlst)) == NULL)
		return (NULL);
	if ((j = (int *)malloc(sizeof(int))) == NULL)
		return (NULL);
	*j = i;
	dlst_lnk_set_cont(lnk, j, sizeof(int));
	return (lnk);
}

int				dlst_contains_int(t_dlst *dlst, int i)
{
	t_dlst_link	*lnk;

	if (!dlst || dlst->size == 0)
		return (0);
	lnk = dlst->link;
	while (lnk)
	{
		if (*((int*)lnk->content) == i)
			return (1);
		lnk = lnk->next;
	}
	return (0);
}
