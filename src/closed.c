/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 09:05:27 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/23 09:05:29 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int     find_closed(t_env *env, char *name)
{
	t_dlst_link *link;

	link = env->closed->link;
	while (link && ft_strcmp(name, ((t_node*)(link->content))->name))
		link = link->next;
	if (link)
		return (link->index);
	else
		return (-1);
}
