/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:54:28 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:54:29 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libdlst.h"

t_dlst_link	*dlst_lnk_cpy(t_dlst_link *from)
{
	if (!from)
		return (NULL);
	return (dlst_lnk_mk(from->content, from->content_size));
}

void		dlst_lnk_cpd(t_dlst_link *from, t_dlst_link *to)
{
	if (!from)
	{
		to->content = NULL;
		to->content_size = 0;
	}
	else
	{
		to->content = from->content;
		to->content_size = from->content_size;
	}
}

void		dlst_lnk_cpcont(t_dlst_link *lnk, void *content, size_t size)
{
	if (!lnk)
		return ;
	if ((lnk->content = (void *)malloc(size)) == NULL)
		return ;
	lnk->content_size = size;
	ft_memcpy(lnk->content, content, size);
}
