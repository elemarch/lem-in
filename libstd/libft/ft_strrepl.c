/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 22:00:14 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/26 23:36:01 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepl(char *src, char *from, char *to)
{
	char *str;
	char *pos;
	char *begin;

	if (!src || !from || !to)
		return (NULL);
	str = ft_strnew(ft_strlen(src) - ft_strlen(from) + ft_strlen(to));
	begin = str;
	pos = ft_strstr(src, from);
	ft_memcpy(str, src, pos - src);
	pos += ft_strlen(from);
	while (*str)
		str++;
	while (*to)
		*str++ = *to++;
	while (*pos != '\0')
		*str++ = *pos++;
	return (begin);
}
