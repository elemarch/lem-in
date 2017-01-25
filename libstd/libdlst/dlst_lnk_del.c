/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:53:53 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:53:53 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void	dlst_lnk_fakedel(void *c, size_t s)
{
	(void)c;
	(void)s;
}

void	dlst_lnk_del(t_dlst_link *lnk)
{
	if (!lnk || !lnk->content)
		return ;
	RFREE(&(lnk->content));
}

void	dlst_lnk_fdel(t_dlst_link *lnk, void (*f)(void *, size_t))
{
	if (!lnk || !f)
		return ;
	f(lnk->content, lnk->content_size);
	FREE(lnk);
}
