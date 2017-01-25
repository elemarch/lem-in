/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:33:23 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/15 19:22:56 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int cn;
	int i1;
	int i2;
	int ret;

	if (size <= 0)
		return (ft_strlen((char *)src));
	if (ft_strlen(dst) >= size)
		return (size + ft_strlen((char *)src));
	ret = ft_strlen(dst) + ft_strlen((char *)src);
	i1 = ft_strlen(dst);
	i2 = 0;
	cn = size - ft_strlen(dst) - 1;
	while (src[i2] && cn != 0)
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
		cn--;
	}
	dst[i1] = '\0';
	return (ret);
}
