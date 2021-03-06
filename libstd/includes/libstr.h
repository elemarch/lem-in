/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 04:15:12 by esaminad          #+#    #+#             */
/*   Updated: 2015/04/12 22:30:25 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTR_H
# define LIBSTR_H

# define STR_EXPAND_THRESHOLD	32

# include "utils.h"
# include "str.h"

# include <stdlib.h>
# include <string.h>

/*
** ------str_add.c
** str_add(t_str *s, char *c)
** Add c at the end of str
** ---------------
** str_adds(t_str *s, t_str *c)
** Add c at the end of str
** ---------------
*/
void		str_add(t_str *s, char *c);
void		str_adds(t_str *s, t_str *c);

/*
** ------str_new.c
** str_new(void)
** Init a new empty string and return a pointer to it.
** ---------------
** str_newc(char *c)
** Init a new string with a copy of c, if no c given, return empty str
** ---------------
** str_news(t_str *s)
** Init a new string with a copy of s, if no s given, return empty str
** ---------------
*/
t_str		*str_new(void);
t_str		*str_newc(char *c);
t_str		*str_news(t_str *s);

/*
** ------str_del.c
** str_del(t_str** s);
** Completely delete the string, freeing its content
** ---------------
** str_clear(t_str *s)
** Reset the string, free its content.
** ---------------
*/
void		str_del(t_str **s);
void		str_clear(t_str *s);

/*
** ------str_set.c
** str_set(t_str *s, char *c)
** Clear the string and set it to the given char*
** ---------------
** TODO
** void		str_place(t_str *s, char *c, size_t pos, size_t len);
*/
void		str_set(t_str *s, char *c);
void		str_fill(t_str *s, char c);

/*
** ------str_pos.c
** str_atc(t_str *s, size_t pos);
** Give a pointer to the pos in the given string, the string is still
** fragmented at this point, use str_fposc to fiddle with the full str
** ---------------
** str_atlst(t_str *s, size_t pos)
** Return the dlst link that contains the string for the given position
** in str, pos will be modified so to fit the pos in the link content
** ---------------
*/
char		*str_atc(t_str *s, size_t pos);
t_dlst_link	*str_atlst(t_str *s, size_t *pos);

/*
** ------str_info.c
** str_tryexpand(t_str *s);
** Tell wheter the str should expand or not
** It's useless to expand if the trailing string is too short
** ---------------
** str_isempty(t_str *s)
** Return 0 if str is empty or the size of str
** ---------------
** str_adds(t_str *s, t_str *c)
** Add c at the end of str
*/
t_bool		str_tryexpand(t_str *s);
size_t		str_isempty(t_str *s);
t_bool		str_isnull(t_str *s);

/*
** ------str_data.c
** str_trylinkexpand(t_dlst_link *lk)
** Check wheter the given link'string can be reallocated or not
** If the string is big enough it wont be touched and false will be returned
** ---------------
** str_flatten(t_str *s)
** Get the full string and merge it in one char *in the first link
** ---------------
** str_setdata(t_str *s, char *c)
** Set the given char *c to be the data of the string, set valid to true
*/
t_bool		str_trylinkexpand(t_dlst_link *lk);
void		str_flatten(t_str *s);
void		str_setdata(t_str *s, char *c);

/*
** ------str_toc.c
** str_toc(t_str *s)
** Make a char *string with the content of str
** ---------------
** str_tocc(t_str *s)
** Same as str_toc but with const char
*/
char		*str_toc(t_str *s);
const char	*str_tocs(t_str *s);

/*
** ------str_size.c
** str_fixsize(t_str *s)
** Fix the str size by looking at the size of every link
** and return the total size
** ---------------
** str_calcsize(t_str *s)
** Recalculate the lenght of each string for each
** link in the string. Do like str_fixsize but with ft_strlen
** ---------------
** str_fixsizelk(t_str *s, t_dlst_link *lk)
** Fix the lenght of the given str by recalculating the link lk
*/
size_t		str_fixsize(t_str *s);
size_t		str_calcsize(t_str *s);
void		str_fixsizelk(t_str *s, t_dlst_link *lk);

/*
** ------str_link.c
*/
void		str_link_split(t_dlst_link *lk, size_t at);

/*
** left
** left justified
** indexof
** lastindexof
** count
** contains
** compare
** chop
** insert
** mid
** prepend
** remove
** replace(t_str *s, size_t pos, int len, t_str *set)
** replace(t_str *s, size_t pos, int len, char *set)
** replace(t_str *s, t_str *search, t_str *set)
** replace(t_str *s, char *search, char *replace)
** replace(t_str *s, t_str *search, char *replace)
** replace(t_str *s, char *search, t_str *replace)
** resize
** right
** rightjustified
** section(t_str *s, char sep, size_t start, int end)
** section(t_str *s, char *sep, size_t start, int end)
** section(t_str *s, t_str *sep, size_t start, int end)
** setnum(t_str *s, int n);
** setnum(t_str *s, uint n);
** setnum(t_str *s, long n);
** setnum(t_str *s, ulong n);
** setnum(t_str *s, float n, int prec);
** simplified(t_str *s) ** trim + \t \n \v \f \r
** split(t_str *s, char sep) ** use dlst
** split(t_str *s, char *sep) ** use dlst
** split(t_str *s, t_str *sep) ** use dlst
** squeeze(t_str** s) ** resize alloc_size to fit size
** startwith(t_str *s, char c)
** startwith(t_str *s, char *c)
** startwith(t_str *s, t_str *c)
** tofloat
** toint
** touint
** tolong
** trimmed
** truncate
*/

#endif
