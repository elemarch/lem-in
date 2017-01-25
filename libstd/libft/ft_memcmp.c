/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 01:48:25 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/09 17:27:46 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*stra;
	char			*strb;

	i = 0;
	stra = (char *)s1;
	strb = (char *)s2;
	while (i < n)
	{
		if (stra[i] != strb[i])
			return ((unsigned char)stra[i] - (unsigned char)strb[i]);
		i++;
	}
	return (0);
}
