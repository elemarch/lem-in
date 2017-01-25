/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_toc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include "libft.h"

char		*str_toc(t_str *s)
{
	char		*str;
	char		*itr;
	t_dlst_link	*lk;

	if (!s || str_isnull(s))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (s->size + 1))))
		return (NULL);
	ft_bzero(str, s->size + 1);
	lk = s->lst.link;
	itr = str;
	while (lk)
	{
		ft_strncat(itr, (char*)lk->content, lk->content_size);
		itr += lk->content_size;
		lk = lk->next;
	}
	return (str);
}

const char	*str_tocc(t_str *s)
{
	char	*str;

	if (!(str = str_toc(s)))
		return (NULL);
	return ((const char*)str);
}
