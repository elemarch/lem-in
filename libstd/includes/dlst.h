/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/30 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <string.h>

/*
** s_list
** ----------------
** size			= count of link currently used
** alloc_size	= count on avaliable links
** link			= pointer to the first link in the list
** ----------------
*/

typedef struct			s_dlst
{
	size_t				size;
	struct s_dlst_link	*link;
	struct s_dlst_link	*end;
}						t_dlst;

/*
** s_dlst_link
** ----------------
** index		= index of the current link in the list
** content		= pointer to a content
** content_size	= size of the content in memory
** prev			= pointer to the previous link
** next			= pointer to the next link
** list			= pointer to the list
** ----------------
*/

typedef struct			s_dlst_link
{
	size_t				index;
	void				*content;
	size_t				content_size;
	struct s_dlst_link	*prev;
	struct s_dlst_link	*next;
	struct s_dlst		*dlst;
}						t_dlst_link;

#endif
