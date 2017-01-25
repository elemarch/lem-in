/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libft.h"
#include "libdlst.h"

void	str_set(t_str *s, char *c)
{
	if (!s)
		return ;
	str_clear(s);
	str_add(s, c);
}

void	str_fill(t_str *s, char c)
{
	char	*str;

	if (!s || str_isnull(s))
		return ;
	if (!(str = ft_strnew(s->size)))
		return ;
	ft_memset(str, c, s->size);
	str_clear(s);
	str_add(s, str);
}

void	str_place(t_str *s, char *c, size_t pos)
{
	t_dlst_link	*lk;
	char		*str;

	if (!s || str_isnull(s) || !c || pos > s->size ||
		(!(lk = str_atlst(s, &pos))))
		return ;
	if (!str_trylinkexpand(lk))
	{
		str_link_split(lk, pos);
		if (!dlst_insert(&(s->lst), lk->index))
			return ;
		lk->next->content = ft_strdup(c);
		lk->next->content_size = ft_strlen(c);
		s->size += lk->next->content_size;
	}
	else
	{
		if (!(str = ft_strmerge((char*)lk->content, c, pos)))
			return ;
		FREE(lk->content);
		lk->content = str;
		str_fixsizelk(s, lk);
	}
}
