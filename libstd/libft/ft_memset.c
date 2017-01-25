/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:02:20 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/04 22:54:05 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char *str;

	if (len > 0)
	{
		str = b;
		while (len-- > 0)
		{
			*str = c;
			str++;
		}
	}
	return (b);
}
