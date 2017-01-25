/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 01:43:47 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/27 01:46:31 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void	lst_clear(t_list **alst)
{
	t_list *lst;
	t_list *tmp;

	if (!alst)
		return ;
	lst = *alst;
	while (lst)
	{
		if (lst->content)
			FREE(lst->content);
		tmp = lst;
		lst = lst->next;
		FREE(tmp);
	}
	*alst = NULL;
	alst = NULL;
}
