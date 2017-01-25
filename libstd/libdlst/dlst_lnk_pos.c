/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:55:07 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:55:07 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst_link	*dlst_lnk_first(t_dlst_link *lnk)
{
	if (!lnk)
		return (NULL);
	while (lnk->prev)
		lnk = lnk->prev;
	return (lnk);
}

t_dlst_link	*dlst_lnk_last(t_dlst_link *lnk)
{
	if (!lnk)
		return (NULL);
	while (lnk->next)
		lnk = lnk->next;
	return (lnk);
}
