/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "utils.h"
# include "dlst.h"

/*
** s_str
** -----------------------------------------------------------------
** lst		= list containing parts of string
** size		= current number of char in the string
** data		= string in char*
** valid	= wheter the char* data is valid or need ot be rewritten
** -----------------------------------------------------------------
*/

typedef struct			s_str
{
	t_dlst				lst;
	size_t				size;
	char				*data;
	t_bool				valid;
}						t_str;

#endif
