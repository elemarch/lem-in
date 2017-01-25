/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 04:12:26 by esaminad          #+#    #+#             */
/*   Updated: 2015/01/20 15:17:10 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDLST_H
# define LIBDLST_H

# include <string.h>
# include <stdlib.h>

# include "dlst.h"
# include "utils.h"

/*
** dlst.c
** --------------------
** dlst_new
** Create a new blank dlst
** --------------------
** dlst_init
** Set the datas of the dlst to null & size to 0
*/

t_dlst		*dlst_new(void);
void		dlst_init(t_dlst *dlst);

/*
** dlst_del.c
** --------------------
** dlst_clear
** Delete every link in the list, free every content and links
** --------------------
** dlst_fclear
** Delete every link in the list, use a function on every links before
** deleting them
** --------------------
** dlst_lclear
** Delete every link, doesnt free the contents
** --------------------
** dlst_del
** Delete a list, every links and every content
** --------------------
** dlst_fdel
** Delete a list, use dlst_fclear on the links
*/

void		dlst_clear(t_dlst *dlst);
void		dlst_fclear(t_dlst *dlst, void (*f)(void *, size_t));
void		dlst_lclear(t_dlst *dlst);
void		dlst_del(t_dlst **lst);
void		dlst_fdel(t_dlst **lst, void (*f)(void *, size_t));

/*
** dlst_pos.c
** --------------------
** dlst_at
** Return a pointer to the link at the given pos in the list
** --------------------
** dlst_at_cont
** Return the content at the given position in the list
** --------------------
** dlst_first
** Return a pointer to the first link in the list
** --------------------
** dlst_last
** Return a pointer to the last link in the list
*/

t_dlst_link	*dlst_at(t_dlst *dlst, size_t index);
void		*dlst_at_cont(t_dlst *dlst, size_t index);
t_dlst_link	*dlst_first(t_dlst *dlst);
t_dlst_link	*dlst_last(t_dlst *dlst);

/*
** dlst_itr.c
** --------------------
** dlst_foreach
** Execute the given function on every link in the list
** --------------------
** dlst_foreach_ex
** Dlst foreach with extended void * variable for extra stuff
*/

void		dlst_foreach(t_dlst *dlst, void(*f)(t_dlst_link *));
void		dlst_foreach_ex(t_dlst *lst, void *ex,
								void(*f)(t_dlst_link *, void *));

/*
** dlst_display.c
** --------------------
** dlst_show_strings
** Display every content in the list as strings
** --------------------
** dlst_show_data
** Display the list size
** --------------------
** dlst_show_content
** Display the content of each link in the list using the given function,
** display every link in the list, even the empty/unused one
** --------------------
** dlst_show_str
** To be used with dlst_show_content, display a link content cast as a string
** --------------------
** dlst_show_int
** To be used with dlst_show_int, display a link content cast as an int
*/

void		dlst_show_strings(t_dlst *dlst);
void		dlst_show_data(t_dlst *dlst);
void		dlst_show_content(t_dlst *dlst, void (*f)(t_dlst_link *));
void		dlst_show_str(t_dlst_link *lnk);
void		dlst_show_int(t_dlst_link *lnk);

/*
** dlst_lnk.c
** --------------------
** dlst_lnk_new
** Create a blank link with every variables init at 0 or NULL
** --------------------
** dlst_lnk_mk
** Create a blank link ant set its content. Remaloc the given content
** --------------------
** dlst_lnk_gen
** User dlst_lnk_mk to make a new link and set the prev and next pointer
** --------------------
** dlst_lnk_set_cont
** Just set the content & content size of the given link, no malloc
** --------------------
** dlst_lnk_repl_cont
** Free the current content and replace with a remalloc of the given content
*/

t_dlst_link	*dlst_lnk_new(void);
t_dlst_link	*dlst_lnk_mk(void *content, size_t content_size);
t_dlst_link	*dlst_lnk_gen(void *c, size_t s, t_dlst_link *p, t_dlst_link *n);
void		dlst_lnk_set_cont(t_dlst_link *lnk, void *content, size_t size);
void		dlst_lnk_repl_cont(t_dlst_link *lnk, void *content, size_t size);

/*
** dlst_lnk_cpy.c
** --------------------
** dlst_lnk_cpy
** Use dlst_lnk_mk to create a new link, remalloc the content
** --------------------
** dlst_lnk_cpd
** Copy the pointer to the content of the first link to the second, no malloc
** --------------------
** dlst_lnk_cpcont
** Remaloc the given content and set it in the given link
*/

t_dlst_link	*dlst_lnk_cpy(t_dlst_link *from);
void		dlst_lnk_cpd(t_dlst_link *from, t_dlst_link *to);
void		dlst_lnk_cpcont(t_dlst_link *lnk, void *content, size_t size);

/*
** dlst_lnk_build.c
** --------------------
** dlst_reindex
** Rebuild the index in every link in the given list
** --------------------
** dlst_lnk_reindex
** Rebuild the index from the given link according to a size
** --------------------
*/

void		dlst_reindex(t_dlst *dlst);
void		dlst_lnk_reindex(t_dlst_link *lnk, t_dlst *dlst);

/*
** dlst_lnk_del.c
** --------------------
** dlst_lnk_fakedel
** Fake function to test dlst_lnk_fdel
** --------------------
** dlst_lnk_del
** Free the content in the given link
** --------------------
** dlst_lnk_fdel
** Use the given function on the given link and free the link
*/

void		dlst_lnk_fakedel(void *c, size_t s);
void		dlst_lnk_del(t_dlst_link *lnk);
void		dlst_lnk_fdel(t_dlst_link *lnk, void (*f)(void *, size_t));

/*
** dlst_lnk_pos.c
** --------------------
** dlst_lnk_first
** Get the head of the list for a given link, rewind
** --------------------
** dlst_lnk_last
** Get the tail of the list for a given link
*/

t_dlst_link	*dlst_lnk_first(t_dlst_link *lnk);
t_dlst_link	*dlst_lnk_last(t_dlst_link *lnk);

/*
** dlst_mod.c
** --------------------
** dlst_emplace
** Insert an empty list link at this position in the list,
** reindex the list after the operation.
** --------------------
** dlst_insert
** Insert an empty list link before this position in the list,
** reindex the list after the operation.
** --------------------
** dlst_swap
** Swap the prev and next pointer from each link at pos1 & pos2,
** reindex the list after the operation.
** --------------------
** dlst_rev
** Reverse the order of every used link in the list, reindex the list.
** --------------------
** dlst_merge
** Copy each link of src at the end of dst, the content will be copied
** with the function *cpy. If no dst given
*/

t_dlst_link	*dlst_emplace(t_dlst *dlst, size_t at);
t_dlst_link	*dlst_insert(t_dlst *dlst, size_t at);
void		dlst_swap(t_dlst *dlst, size_t pos1, size_t pos2);
void		dlst_rev(t_dlst *dlst);
void		dlst_merge(t_dlst *dst, t_dlst *src, void *(*cpy)(void *));

/*
** dlst_str.c
** --------------------
** dlst_push_back_str
** Add a given str in the last avaliable link in the list
*/

t_dlst_link	*dlst_push_back_str(t_dlst *dlst, char *s);

/*
** dlst_int.c
** --------------------
** dlst_push_back_int
** Add a given int in the last avaliable link in the list
*/

t_dlst_link	*dlst_push_back_int(t_dlst *dlst, int i);
int			dlst_contains_int(t_dlst *dlst, int i);

/*
** dlst_push.c
** --------------------
** dlst_push_back_c
** Push back the dlst and set the content to the given stuff
** --------------------
** dlst_push_back
** Return a pointer to the next spot in the list,
** also increase list size
** --------------------
** dlst_pop_back
** Remove the last link in the list, reduce size by 1, free content
** and delete link
** --------------------
** dlst_erase
** Remove a link in the list at the given pos, reduce size by 1, free
** content and link
*/

t_dlst_link	*dlst_push_back_c(t_dlst *dlst, void *cont, size_t sz);
t_dlst_link	*dlst_push_back(t_dlst *dlst);
void		dlst_pop_back(t_dlst *dlst);
void		dlst_erase(t_dlst *dlst, size_t at);

/*
** dlst_lnk_swap.c
** --------------------
** dlst_swap_cont
** Swap the content pointer from both list link, no remalloc
*/

void		dlst_swap_cont(t_dlst_link *l1, t_dlst_link*l2);

/*
** dlst_insert_sort.c
** --------------------
** dlst_insert_sort
** Insert in the given list using emplace, choose the position
** where to insert with the given function
** --------------------
** dlst_isort_int
** Used in dlst_insert_sort to sort int with dlst_insert_sort
** --------------------
** dlst_isort_str
** Used in dlst_insert_sort to sort str with dlst_insert_sort
*/

t_dlst_link	*dlst_insert_sort(t_dlst *v, void *c, size_t cont_s,
								size_t (*f)(void *, t_dlst *));
size_t		dlst_isort_int(void *c, t_dlst *dlst);
size_t		dlst_isort_str(void *c, t_dlst *dlst);

/*
** dlst_to_array.c
** --------------------
** dlst_to_array
** Create a static array of pointer with each content pointer
** of the dlst. This array is not null-terminated, you should
** know its size before using it.
*/
void		**dlst_to_array(t_dlst *lst);

#endif
