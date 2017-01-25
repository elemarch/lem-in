/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libdlst.h"
#include "libft.h"

void	str_link_split(t_dlst_link *lk, size_t at)
{
	t_dlst_link *lnk;

	if (!lk || at > lk->content_size || at == 0 ||
		!(lnk = dlst_insert(lk->dlst, lk->index)))
		return ;
	lnk->content = ft_strdup((char*)(lk->content + at));
	lnk->content_size = ft_strlen((char*)(lnk->content));
	ft_strclr((char*)(lk->content + at + 1));
	lk->content_size = lk->content_size - at;
}
