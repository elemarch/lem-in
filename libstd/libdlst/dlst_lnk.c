/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_lnk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:53:15 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:53:15 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdlst.h"
#include "libft.h"

t_dlst_link	*dlst_lnk_new(void)
{
	t_dlst_link *lk;

	if ((lk = (t_dlst_link *)malloc(sizeof(t_dlst_link))) == NULL)
		return (NULL);
	lk->index = 0;
	lk->content = NULL;
	lk->content_size = 0;
	lk->prev = NULL;
	lk->next = NULL;
	lk->dlst = NULL;
	return (lk);
}

t_dlst_link	*dlst_lnk_mk(void *content, size_t content_size)
{
	t_dlst_link *lk;

	if (!(lk = dlst_lnk_new()))
		return (NULL);
	if (content_size > 0)
	{
		if ((lk->content = (void *)malloc(content_size)) == NULL)
		{
			FREE(lk);
			return (NULL);
		}
		lk->content_size = content_size;
		ft_memcpy(lk->content, content, content_size);
	}
	return (lk);
}

t_dlst_link	*dlst_lnk_gen(void *c, size_t s, t_dlst_link *p, t_dlst_link *n)
{
	t_dlst_link *lk;

	if ((lk = dlst_lnk_mk(c, s)) == NULL)
		return (NULL);
	lk->prev = p;
	lk->next = n;
	return (lk);
}

void		dlst_lnk_set_cont(t_dlst_link *lnk, void *content, size_t size)
{
	if (!lnk)
		return ;
	lnk->content = content;
	lnk->content_size = size;
}

void		dlst_lnk_repl_cont(t_dlst_link *lnk, void *content, size_t size)
{
	if (!lnk)
		return ;
	if (lnk->content)
		FREE(lnk->content);
	dlst_lnk_cpcont(lnk, content, size);
}
