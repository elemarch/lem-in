/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_insert_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:52:34 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:52:34 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libdlst.h"

t_dlst_link	*dlst_insert_sort(t_dlst *v, void *c, size_t cont_s,
								size_t (*f)(void *, t_dlst *))
{
	t_dlst_link	*lnk;
	size_t		pos;

	pos = 0;
	if (!v || !f || !c)
		return (NULL);
	pos = f(c, v);
	lnk = dlst_emplace(v, pos);
	dlst_lnk_repl_cont(lnk, c, cont_s);
	return (lnk);
}

size_t		dlst_isort_int(void *c, t_dlst *dlst)
{
	t_dlst_link	*lnk;
	int			i1;

	if (!dlst || !c || !dlst->link)
		return (0);
	i1 = *((int *)c);
	lnk = dlst->link;
	if (!lnk || dlst->size == 0)
		return (0);
	while (lnk)
	{
		if (!lnk->content)
			return (lnk->index);
		if (*((int *)lnk->content) < i1)
		{
			if (lnk->next)
				lnk = lnk->next;
			else
				return (lnk->index + 1);
		}
		else
			return (lnk->index);
	}
	return (0);
}

size_t		dlst_isort_str(void *c, t_dlst *dlst)
{
	t_dlst_link	*lnk;
	char		*str;

	if (!dlst || !c || !dlst->link)
		return (0);
	str = (char *)c;
	lnk = dlst->link;
	if (!lnk || dlst->size == 0)
		return (0);
	while (lnk)
	{
		if (!lnk->content)
			return (lnk->index);
		if (ft_strcmp((char *)lnk->content, str) < 1)
		{
			if (lnk->next)
				lnk = lnk->next;
			else
				return (lnk->index + 1);
		}
		else
			return (lnk->index);
	}
	return (0);
}
