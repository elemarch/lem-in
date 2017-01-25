/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:58:09 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/08 16:29:12 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	lst_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (!alst || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		(*del)(lst->content, lst->content_size);
		lst = lst->next;
	}
	*alst = NULL;
	alst = NULL;
}
