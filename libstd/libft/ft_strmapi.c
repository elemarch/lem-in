/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 04:21:26 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/07 16:17:43 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	size = ft_strlen((char *)s);
	if (!(str = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
