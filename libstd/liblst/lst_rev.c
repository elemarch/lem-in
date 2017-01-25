/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 19:07:21 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/26 01:00:03 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	lst_rev(t_list **alst)
{
	t_list *prev;
	t_list *next;
	t_list *lst;

	if (!alst || !*alst)
		return ;
	prev = NULL;
	lst = *alst;
	while (lst)
	{
		next = lst->next;
		if (lst == *alst)
			lst->next = NULL;
		lst->next = prev;
		prev = lst;
		if (!next)
			*alst = lst;
		lst = next;
	}
}
