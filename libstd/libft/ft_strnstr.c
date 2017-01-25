/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:04:09 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/10 22:27:08 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (!s2 || *s2 == '\0')
		return ((char *)s1);
	if (ft_strlen((char *)s2) > n - 1)
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	while (n != 0)
	{
		if (*s1 == '\0')
			return (NULL);
		if (*s1 == s2[i])
		{
			i++;
			if (s2[i] == '\0')
				return ((char *)(s1 - ft_strlen((char *)s2)) + 1);
		}
		else
			i = 0;
		s1++;
		n--;
	}
	return (NULL);
}
