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

#include "libft.h"
#include "libdlst.h"

t_dlst_link	*dlst_push_back_str(t_dlst *dlst, char *s)
{
	t_dlst_link	*lnk;

	if (!dlst)
		return (NULL);
	if ((lnk = dlst_push_back(dlst)) == NULL)
		return (NULL);
	dlst_lnk_set_cont(lnk, ft_strdup(s), ft_strlen(s));
	return (lnk);
}
