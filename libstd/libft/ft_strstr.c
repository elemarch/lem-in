/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:16:18 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/15 20:55:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int	c1;
	int	c2;

	c1 = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	while (s1[c1] != '\0')
	{
		c2 = 0;
		while (s1[c1] == s2[c2] && s1[c1] != '\0' && s2[c2] != '\0')
		{
			c1++;
			c2++;
		}
		if (s2[c2] == '\0')
			return ((char *)s1 + c1 - c2);
		else
			c1 -= c2;
		c1++;
	}
	return (NULL);
}
