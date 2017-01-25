/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

t_str	*str_new(void)
{
	t_str *s;

	if (!(s = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	s->data = NULL;
	s->size = 0;
	s->lst.size = 0;
	s->lst.link = NULL;
	s->valid = FALSE;
	return (s);
}

t_str	*str_newc(char *c)
{
	t_str *s;

	if (!(s = str_new()))
		return (NULL);
	if (c)
		str_add(s, c);
	return (s);
}

t_str	*str_news(t_str *s)
{
	t_str *ns;

	if (!(ns = str_new()))
		return (NULL);
	if (s)
		str_adds(ns, s);
	return (ns);
}
