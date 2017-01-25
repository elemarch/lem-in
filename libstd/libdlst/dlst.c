/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:47:20 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:49:35 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"

t_dlst	*dlst_new(void)
{
	t_dlst *dlst;

	if ((dlst = (t_dlst *)malloc(sizeof(t_dlst))) == NULL)
		return (NULL);
	dlst->size = 0;
	dlst->link = NULL;
	dlst->end = NULL;
	return (dlst);
}

void	dlst_init(t_dlst *dlst)
{
	if (!dlst)
		return ;
	dlst->size = 0;
	dlst->link = NULL;
	dlst->end = NULL;
}
