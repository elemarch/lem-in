/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:12:47 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/25 17:25:48 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

int		lst_psh_f(t_list **alst, void const *cont, size_t cont_s)
{
	t_list *lst;

	if ((lst = lst_new(cont, cont_s)) == NULL)
		return (0);
	if (!alst)
		return (0);
	if (*alst)
		lst->next = *alst;
	*alst = lst;
	return (1);
}

int		lst_psh_b(t_list **alst, void const *cont, size_t cont_s)
{
	t_list *lst;
	t_list *itr;

	if ((lst = lst_new(cont, cont_s)) == NULL)
		return (0);
	if (!alst)
		return (0);
	if (*alst)
	{
		itr = *alst;
		while (itr->next)
			itr = itr->next;
		itr->next = lst;
	}
	else
		*alst = lst;
	return (1);
}
