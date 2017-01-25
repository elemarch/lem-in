/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:54:42 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:54:42 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

void	dlst_swap_cont(t_dlst_link *l1, t_dlst_link *l2)
{
	void	*cont;
	size_t	size;

	if (!l1 || !l2)
		return ;
	cont = l1->content;
	size = l1->content_size;
	l1->content = l2->content;
	l1->content_size = l2->content_size;
	l2->content = cont;
	l2->content_size = size;
}
