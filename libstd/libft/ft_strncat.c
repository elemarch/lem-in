/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:29:47 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/15 19:08:39 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *str;

	str = s1;
	while (*str)
		str++;
	while (*s2 && n-- > 0)
		*str++ = *s2++;
	*str = '\0';
	return (s1);
}
