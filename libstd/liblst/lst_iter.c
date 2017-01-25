/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:37:43 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/09 15:53:17 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	lst_iter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *l;

	if (!lst || !f)
		return ;
	l = lst;
	while (l)
	{
		(*f)(l);
		l = l->next;
	}
}
