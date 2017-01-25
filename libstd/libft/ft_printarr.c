/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:39:00 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/06 17:04:27 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printarr(char **arr)
{
	int i;

	i = 0;
	ft_putstr("[");
	while (arr[i])
	{
		if (arr[i][1] == '\0')
			break ;
		ft_putstr(i != 0 ? ", \"" : "\"");
		ft_putstr(arr[i]);
		ft_putchar('"');
		i++;
	}
	ft_putstr("]\n");
}
