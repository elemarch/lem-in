/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:48:03 by esaminad          #+#    #+#             */
/*   Updated: 2015/03/17 12:44:43 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;
	char	*sitr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	if (!(str = (char *)malloc((l1 + l2 + 1) * sizeof(char))))
		return (NULL);
	sitr = str;
	while (l1-- > 0)
		*sitr++ = *s1++;
	while (l2-- > 0)
		*sitr++ = *s2++;
	*sitr = '\0';
	return (str);
}

char	*ft_strfjoin(char *s1, char *s2)
{
	char *buff;

	buff = ft_strjoin(s1, s2);
	if (s1)
		FREE(s1);
	return (buff);
}

char	*ft_strmerge(char *dst, char *src, size_t at)
{
	size_t	t;
	char	*str;

	if (!dst)
		return (NULL);
	t = ft_strlen(dst) + ft_strlen(src);
	if (!src || at > t)
		return (ft_strdup(dst));
	if (!(str = ft_strnew(t)))
		return (NULL);
	ft_strncat(str, dst, at);
	ft_strcat(str, src);
	if (dst[at + 1] != '\0')
		ft_strcat(str, dst + at + 1);
	return (src);
}
