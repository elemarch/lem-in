/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libstr.h"

t_bool	str_tryexpand(t_str *s)
{
	if (!s)
		return (FALSE);
	if (s->lst.size == 0 || !s->lst.end || !s->lst.end->content ||
		s->lst.end->content_size < STR_EXPAND_THRESHOLD)
		return (TRUE);
	return (FALSE);
}

size_t	str_isempty(t_str *s)
{
	if (!s || str_isnull(s))
		return (0);
	return (s->size);
}

t_bool	str_isnull(t_str *s)
{
	if (!s || s->size == 0 || s->lst.size == 0)
		return (FALSE);
	return (TRUE);
}
