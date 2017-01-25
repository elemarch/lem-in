/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:43:52 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/09 15:46:22 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list		*lst_cpy(t_list *lst)
{
	t_list *l;

	if (!lst)
		return (NULL);
	l = lst_new(lst->content, lst->content_size);
	return (l);
}
