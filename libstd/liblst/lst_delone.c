/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:54:09 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/11 13:53:46 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void		lst_delone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (!alst || !del)
		return ;
	lst = *alst;
	if (lst)
	{
		(*del)(lst->content, lst->content_size);
		FREE(lst);
	}
	*alst = NULL;
	alst = NULL;
}
