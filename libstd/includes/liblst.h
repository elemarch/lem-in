/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:56:50 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/06 11:16:26 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

# include <string.h>
# include <stdlib.h>

# include "utils.h"
# include "lst.h"

t_list	*lst_new(void const *content, size_t content_size);
t_list	*lst_n(void const *content, size_t content_size);
void	lst_delone(t_list **alst, void (*del)(void *, size_t));
void	lst_del(t_list **alst, void (*del)(void *, size_t));
void	lst_clear(t_list **alst);
void	lst_add(t_list **alst, t_list *new);
void	lst_iter(t_list *lst, void (*f)(t_list *elem));
t_list	*lst_cpy(t_list *lst);
t_list	*lst_map(t_list *lst, t_list *(*f)(t_list *elem));
int		lst_psh_f(t_list **alst, void const *cont, size_t cont_s);
int		lst_psh_b(t_list **alst, void const *cont, size_t cont_s);
void	lst_rev(t_list **alst);

#endif
