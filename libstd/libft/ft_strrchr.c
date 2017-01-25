/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:10:59 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/14 15:28:36 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char *pos;
	char *str;

	pos = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			pos = str;
		str++;
	}
	if (c == 0)
		return (str != NULL ? (char *)str : NULL);
	return (pos);
}
