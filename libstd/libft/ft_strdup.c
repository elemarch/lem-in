/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:02:49 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/15 19:01:38 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*stri;

	if (!s1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	stri = str;
	while (*s1 != '\0')
		*stri++ = *s1++;
	*stri = '\0';
	return (str);
}

char	*ft_strdups(const char *s1, size_t *sz)
{
	char	*str;
	char	*stri;

	if (!s1 || !sz)
		return (NULL);
	*sz = (ft_strlen((char *)s1));
	if (!(str = (char *)malloc(sizeof(char) * ((*sz) + 1))))
		return (NULL);
	stri = str;
	while (*s1 != '\0')
		*stri++ = *s1++;
	*stri = '\0';
	return (str);
}

void	*ft_memdup(void *s1)
{
	char	*s;
	char	*str;
	char	*stri;

	if (!s1)
		return (NULL);
	s = s1;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	stri = str;
	while (*s != '\0')
		*stri++ = *s++;
	*stri = '\0';
	return ((void*)str);
}
