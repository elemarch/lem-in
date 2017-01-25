/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:52:58 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:52:59 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void	**dlst_to_array(t_dlst *lst)
{
	void		**ar;
	void		**begin;
	t_dlst_link	*lnk;

	if (!lst || lst->size == 0 || !lst->link)
		return (NULL);
	if (!(ar = malloc(sizeof(void*) * lst->size)))
		return (NULL);
	begin = ar;
	lnk = lst->link;
	while (lnk)
	{
		*ar = lnk->content;
		ar++;
		lnk = lnk->next;
	}
	return (begin);
}
