/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 06:52:07 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/08 06:52:07 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libdlst.h"

void	dlst_show_strings(t_dlst *dlst)
{
	t_dlst_link *lnk;

	if (!dlst || !dlst->link)
		return ;
	lnk = dlst->link;
	while (lnk)
	{
		if (lnk->content)
		{
			ft_putstr((char *)lnk->content);
			ft_putchar('\n');
		}
		lnk = lnk->next;
	}
}

void	dlst_show_data(t_dlst *dlst)
{
	ft_putstr("Showing data for dlst\nSIZE :");
	ft_putnbr((int)dlst->size);
	ft_putstr("\n");
}

void	dlst_show_content(t_dlst *dlst, void (*f)(t_dlst_link *))
{
	ft_putstr("CONTENT : (");
	dlst_foreach(dlst, f);
	ft_putstr(")\n");
}

void	dlst_show_str(t_dlst_link *lnk)
{
	ft_putstr("[");
	if (lnk && lnk->content)
		ft_putstr((char *)lnk->content);
	else
		ft_putstr("NULL");
	ft_putstr("]");
}

void	dlst_show_int(t_dlst_link *lnk)
{
	ft_putstr("[");
	if (lnk && lnk->content)
		ft_putnbr(*((int *)lnk->content));
	else
		ft_putstr("NULL");
	ft_putstr("]");
}
